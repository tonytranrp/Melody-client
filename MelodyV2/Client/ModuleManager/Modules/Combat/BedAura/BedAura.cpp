#include "BedAura.h"
#include "../../../../Client.h"
#include "BedAura.h"
#include "../../../../Client.h"

BedAura::BedAura() : Module("BedAura", "Automatically places and explodes beds in the Nether and End.", Category::COMBAT) {
    addSlider<int>("Delay", "The delay between placing beds in ticks.", ValueType::INT_T, &delay, 0, 20);
    addBoolCheck("Strict Direction", "Only places beds in the direction you are facing.", &strictDirection);
    addSlider<float>("Target Range", "The range at which players can be targeted.", ValueType::FLOAT_T, &targetRange, 0.f, 5.f);
    addSlider<float>("Min Damage", "The minimum damage to inflict on your target.", ValueType::FLOAT_T, &minDamage, 0.f, 20.f);
    addSlider<float>("Max Self Damage", "The maximum damage to inflict on yourself.", ValueType::FLOAT_T, &maxSelfDamage, 0.f, 20.f);
    addBoolCheck("Anti Suicide", "Will not place and break beds if they will kill you.", &antiSuicide);
    addBoolCheck("Auto Switch", "Switches to and from beds automatically.", &autoSwitch);
    addBoolCheck("Pause on Eat", "Pauses while eating.", &pauseOnEat);
    addBoolCheck("Pause on Drink", "Pauses while drinking.", &pauseOnDrink);
    addBoolCheck("Pause on Mine", "Pauses while mining.", &pauseOnMine);
    addBoolCheck("Render", "Renders the block where it is placing a bed.", &render);
    addColorPicker("Side Color", "The side color for positions to be placed.", &sideColor);
    addColorPicker("Line Color", "The line color for positions to be placed.", &lineColor);
}

void BedAura::onEnable() {
    timer = delay;
    direction = CardinalDirection::North;
}

void BedAura::onDisable() {
    target = nullptr;
    placePos = Vec3<int>(0, 0, 0);
    breakPos = Vec3<int>(0, 0, 0);
}

void BedAura::onNormalTick(Actor* actor) {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    if (!localPlayer) return;

    // Check if beds can explode here
    if (localPlayer->dimension->id == 0) {
        Notifications::addNotifBox("You can't blow up beds in this dimension, disabling.", 5.f);
        setEnabled(false);
        return;
    }

  

    // Find a target
    target = getClosestPlayer(targetRange);
    if (target == nullptr) {
        placePos = Vec3<int>(0, 0, 0);
        breakPos = Vec3<int>(0, 0, 0);
        return;
    }

    if (breakPos.x == 0 && breakPos.y == 0 && breakPos.z == 0) {
        placePos = findPlace(target);
    }

    // Place bed
    if (timer <= 0 && placeBed(placePos)) {
        timer = delay;
    }
    else {
        timer--;
    }

    if (breakPos.x == 0 && breakPos.y == 0 && breakPos.z == 0) breakPos = findBreak();
    breakBed(breakPos);
}

bool BedAura::canPlaceBed(const Vec3<int>& pos) {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    BlockSource* region = localPlayer->dimension->blockSource;

    if (!region->getBlock(pos)->blockLegacy->material->isSolidBlocking()) return false;
    if (!region->getBlock(pos.addcons(0, 0, 1))->blockLegacy->material->isSolidBlocking()) return false;

    Vec3<float> eyePos = localPlayer->getEyePos();
    Vec3<float> blockPos = Vec3<float>(pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f);
    if (eyePos.dist(blockPos) > 5.0f) return false;

    return true;
}
Vec3<int> BedAura::findPlace(Player* target) {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    Vec3<int> targetPos = target->stateVectorComponent->pos.toInt();

    for (int y = -1; y <= 1; y++) {
        for (CardinalDirection dir : {CardinalDirection::North, CardinalDirection::South, CardinalDirection::East, CardinalDirection::West}) {
            if (strictDirection && dir != CardinalDirection::North) continue; // Assuming player is always facing North for simplicity

            Vec3<int> bedPos = targetPos.add(Vec3<int>(0, y, 0));
            Vec3<int> bedHead = bedPos;
            switch (dir) {
            case CardinalDirection::North: bedHead = bedPos.add(Vec3<int>(0, 0, -1)); break;
            case CardinalDirection::South: bedHead = bedPos.add(Vec3<int>(0, 0, 1)); break;
            case CardinalDirection::East: bedHead = bedPos.add(Vec3<int>(1, 0, 0)); break;
            case CardinalDirection::West: bedHead = bedPos.add(Vec3<int>(-1, 0, 0)); break;
            }

            if (canPlaceBed(bedPos) && canPlaceBed(bedHead)) {
                float targetDamage = calculateBedDamage(target, bedPos.toFloat());
                float selfDamage = calculateBedDamage(localPlayer, bedPos.toFloat());

                if (targetDamage >= minDamage && selfDamage < maxSelfDamage &&
                    (selfDamage > 0)) {
                    direction = dir;
                    return bedPos;
                }
            }
        }
    }

    return Vec3<int>(0, 0, 0);
}

Vec3<int> BedAura::findBreak() {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    BlockSource* region = localPlayer->dimension->blockSource;

    for (int x = -5; x <= 5; x++) {
        for (int y = -5; y <= 5; y++) {
            for (int z = -5; z <= 5; z++) {
                Vec3<int> pos = localPlayer->stateVectorComponent->pos.add(Vec3<float>(x, y, z)).toInt();
                Block* block = region->getBlock(pos);
                if (block->blockLegacy->blockId == 418) { // Bed block ID
                    float targetDamage = calculateBedDamage(target, pos.toFloat());
                    float selfDamage = calculateBedDamage(localPlayer, pos.toFloat());

                    if (targetDamage >= minDamage && selfDamage < maxSelfDamage &&
                        (selfDamage > 0)) {
                        return pos;
                    }
                }
            }
        }
    }

    return Vec3<int>(0, 0, 0);
}

bool BedAura::placeBed(const Vec3<int>& pos) {
    if (pos.x == 0 && pos.y == 0 && pos.z == 0) return false;

    LocalPlayer* localPlayer = mc.getLocalPlayer();
    int bedSlot = findBedInHotbar();
    if (bedSlot == -1 && !autoSwitch) return false;

    float yaw = 0.f;
    switch (direction) {
    case CardinalDirection::East: yaw = 90.f; break;
    case CardinalDirection::South: yaw = 180.f; break;
    case CardinalDirection::West: yaw = -90.f; break;
    default: break;
    }

    int prevSlot = localPlayer->getPlayerInventory()->selectedSlot;
    if (autoSwitch) localPlayer->getPlayerInventory()->selectedSlot = bedSlot;

    localPlayer->rotationComponent->rotation = Vec2<float>(localPlayer->rotationComponent->rotation.x, yaw);
    localPlayer->swing();

    GameMode* gameMode = localPlayer->getGameMode();
    gameMode->buildBlock(pos, Math::random(0, 5), false);

    if (autoSwitch) localPlayer->getPlayerInventory()->selectedSlot = prevSlot;

    breakPos = pos;
    return true;
}

void BedAura::breakBed(const Vec3<int>& pos) {
    if (pos.x == 0 && pos.y == 0 && pos.z == 0) return;
    breakPos = Vec3<int>(0, 0, 0);

    LocalPlayer* localPlayer = mc.getLocalPlayer();
    BlockSource* region = localPlayer->dimension->blockSource;
    if (region->getBlock(pos)->blockLegacy->blockId != 418) return; // Bed block ID

    localPlayer->swing();
    GameMode* gameMode = localPlayer->getGameMode();
    gameMode->destroyBlock(pos, 0);
}

float BedAura::calculateBedDamage(Player* player, const Vec3<float>& bedPos) {
    Vec3<float> playerPos = player->stateVectorComponent->pos;
    float distance = playerPos.dist(bedPos);
    float impact = (1.0f - (distance / 10.0f));
    float damage = (impact * impact + impact) / 2 * 7 * 10 + 1;

    // Apply basic armor reduction (simplified)
    int armorPoints = 0;
    for (int i = 0; i < 4; i++) {
        ItemStack* armor = player->getArmor(i);
        if (armor && armor->item) {
            armorPoints += ((ArmorItem*)armor->getItemPtr())->armorValue;
        }
    }
    float armorToughness = 0.0f; // Simplified, ignore toughness
    damage = damage * (1 - std::min(20.0f, std::max(armorPoints / 5.0f, armorPoints - damage / (2 + armorToughness / 4))) / 25);

    return damage;
}

Player* BedAura::getClosestPlayer(float range) {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    Player* closest = nullptr;
    float closestDist = range * range;

    for (auto& player : mc.getLevel()->getRuntimeActorList()) {
        if (!player->isPlayer() || player == localPlayer) continue;

        float dist = player->stateVectorComponent->pos.distanceTo(localPlayer->stateVectorComponent->pos);
        if (dist < closestDist) {
            closestDist = dist;
            closest = (Player*)player;
        }
    }

    return closest;
}

int BedAura::findBedInHotbar() {
    LocalPlayer* localPlayer = mc.getLocalPlayer();
    PlayerInventory* inventory = localPlayer->getPlayerInventory();

    for (int i = 0; i < 9; i++) {
        ItemStack* stack = inventory->inventory->getItemStack(i);
        if (stack && stack->item && stack->getItemPtr()->itemId == 418) { // Bed item ID
            return i;
        }
    }

    return -1;
}
void BedAura::onRender(MinecraftUIRenderContext* renderCtx) {
    if (!render || (placePos.x == 0 && placePos.y == 0 && placePos.z == 0) || breakPos.x != 0 || breakPos.y != 0 || breakPos.z != 0) return;

    Vec3<float> pos = placePos.toFloat();
    AABB bb;

    switch (direction) {
    case CardinalDirection::North:
        bb = AABB(pos, pos.add(Vec3<float>(1, 0.5625f, 2)));
        break;
    case CardinalDirection::South:
        bb = AABB(pos.sub(Vec3<float>(0, 0, 1)), pos.add(Vec3<float>(1, 0.5625f, 1)));
        break;
    case CardinalDirection::East:
        bb = AABB(pos.sub(Vec3<float>(1, 0, 0)), pos.add(Vec3<float>(1, 0.5625f, 1)));
        break;
    case CardinalDirection::West:
        bb = AABB(pos, pos.add(Vec3<float>(2, 0.5625f, 1)));
        break;
    }

    // Draw the box using your rendering utilities
    RenderUtils::drawBox(bb, sideColor, lineColor, 1.5f, true, true);
}

std::string BedAura::getModName() {
    if (target) {
        return "BedAura [" + std::string(target->getNameTag()->c_str()) + "]";
    }
    else {
        return "BedAura";
    }
}