#pragma once
#include "../../Module.h"
#include "../../../../../Utils/Math.h"

#include <vector>
enum class CardinalDirection {
    North,
    South,
    East,
    West
};

class BedAura : public Module {
private:
    // Settings
    int delay = 9;
    bool strictDirection = false;
    float targetRange = 4.0f;
    float minDamage = 7.0f;
    float maxSelfDamage = 7.0f;
    bool antiSuicide = true;
    bool autoSwitch = true;
    bool pauseOnEat = true;
    bool pauseOnDrink = true;
    bool pauseOnMine = true;
    bool render = true;
    UIColor sideColor = UIColor(15, 255, 211, 75);
    UIColor lineColor = UIColor(15, 255, 211, 255);

    // Internal variables
    CardinalDirection direction;
    Player* target;
    Vec3<int> placePos;
    Vec3<int> breakPos;
    int timer;

    // Helper functions
    bool canPlaceBed(const Vec3<int>& pos);
    Vec3<int> findPlace(Player* target);
    Vec3<int> findBreak();
    bool placeBed(const Vec3<int>& pos);
    void breakBed(const Vec3<int>& pos);
    float calculateBedDamage(Player* player, const Vec3<float>& bedPos);
    Player* getClosestPlayer(float range);
    int findBedInHotbar();

public:
    BedAura();
    virtual void onEnable() override;
    virtual void onDisable() override;
    virtual void onNormalTick(Actor* actor) override;
    virtual void onRender(MinecraftUIRenderContext* renderCtx) override;
    virtual std::string getModName() override;
};