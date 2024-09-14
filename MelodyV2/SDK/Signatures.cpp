#include "Signatures.h"

//gamedata
DEFINE(Sigs::gamedata::isKeyDown, "4C 8D 05 ?? ?? ?? ?? 89 54 24 20 88 4C 24 24")
DEFINE(Sigs::gamedata::sendKey, "48 ? ? 48 ? ? ? 4C 8D 05 ? ? ? ? 89")

//packet
DEFINE(Sigs::packet::ModEquipmentPacket, "48 89 5C 24 08 48 89 74 24 10 57 48 81 EC ? ? ? ? 41 8B F9 48 8B DA")
DEFINE(Sigs::packet::AnimatePacket, "48 89 5C 24 10 48 89 74 24 20 48 89 4C 24 08 57 48 83 EC ? 8B FA 48 8B D9")
DEFINE(Sigs::packet::MobEffectPacket, "33 C0 C7 41 08 ? ? ? ? 48 89 41 ? 48 89 41 ? 89 41 28 48 8D 05 ? ? ? ? 48 89 01 8B 44 24 ?")
DEFINE(Sigs::packet::InventoryTransactionPacket, "40 53 48 83 EC ? 45 33 C9 C7 41 08 ? ? ? ?")
DEFINE(Sigs::packet::InteractPacket_cctor, "48 ?? ?? ?? ? ?? ?? ?? ec ? ?? ?? ?? c7 41 ? ? ? ? ? ?? ?? ? ? ? ? ? ?? ?? ?? ? ? ? ?? c0 ?? ?? ?? ? ?? ?? ?? ? ?? ?? ? ?? ?? ?? ? ? ? ? ?? ?? ?? ?? ??")
DEFINE(Sigs::packet::MovePlayerPacket, "48 ?? ?? ?? ? ?? ?? 6C ?? ? 48 ?? 4C ?? ? ?? ?? ?? ?? ?? ?? ?? ? ?? ?? ?? 48 ?? F2 ?? ?? D9")
DEFINE(Sigs::packet::MinecraftPacket, "40 53 48 83 ec ? 45 33 c0 48 8b d9 ff ca 81 fa")
DEFINE(Sigs::packet::ItemUseOnActorInventoryTransaction, "48 89 5c 24 ? 57 48 83 ec ? 48 8d 59 ? c7 41 ? ? ? ? ? 48 8d 05 ? ? ? ? 48 89 5c 24 ? 48 89 01 48 8b f9 48 8b cb e8 ? ? ? ? 33 c9 48 8d 05 ? ? ? ? 48 89 4b ? 0f 57 c0 48 89 4b ? 48 89 4b ? 48 8b 5c 24 ? 48 89 07 48 8d 05 ? ? ? ? 48 89 4f ? 89 4f")
//gamemode
DEFINE(Sigs::gamemode::getDestroyRate, "48 89 5C 24 ? 57 48 83 EC 30 48 8B F9 0F 29 74 24 ? 48 8B 49 08 E8")
DEFINE(Sigs::gamemode::baseUseItem, "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 60 48 8B F2 48 8B F9 45 33 F6 4C 89 75 08 48 8D 4D 08 E8 ? ? ? ? 90 48")

//enchantutils
DEFINE(Sigs::enchantutils::getenchantlevel, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B F2 0F B6 D9")
//tessellator
DEFINE(Sigs::tessellator::begin, "48 89 5C 24 ? 56 48 83 EC ? 80 B9 ? ? ? ? ? 45 0F B6")
DEFINE(Sigs::tessellator::vertex, "40 57 48 81 EC ? ? ? ? 0F 29 7C ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 8B 81")
DEFINE(Sigs::tessellator::color, "80 b9 ? ? ? ? ? 4c 8b c1 75")
DEFINE(Sigs::tessellator::setRotation, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? F3 41 0F 10")
DEFINE(Sigs::tessellator::resetTransform, "40 53 48 81 ec ? ? ? ? c6 81 ? ? ? ? ? 48 8b d9 84 d2")
DEFINE(Sigs::tessellator::renderMeshImmediately, "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 49 8B F8 48 8B DA 48 8B F1 80 BA ? ? ? ? ? 0F 85 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 44 24 ? 48 C7 44 24 ? ? ? ? ? 0F 28 44 24 ? 66 0F 7F 44 24 ?")

//materialptr
DEFINE(Sigs::materialptr::createMaterial, "48 8B 05 ? ? ? ? 48 8D 55 ? 48 8D 0D ? ? ? ? 48 8B 40 ? FF 15 ? ? ? ? 48 8B F8")

//actor
DEFINE(Sigs::actor::getNameTag, "48 83 EC ? 48 8B 81 ? ? ? ? 48 85 C0 74 3B 48 8B 08 BA ? ? ? ? 48 8B 40 ? 48 2B C1 48 C1 F8 ? 66 3B D0 73 17")

//player
DEFINE(Sigs::player::getDestroyProgress, "48 89 5C 24 ? 57 48 83 EC 30 F3 0F 10 8A")

//blocksource
DEFINE(Sigs::blocksource::getSeenPercent, "40 55 57 41 54 41 55 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84")

//NetworkItemStackDescriptor
DEFINE(Sigs::networkitemstackdescriptor::constructor, "48 89 5C 24 ? 55 56 57 41 56 41 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 48 8B FA 48 8B F1 48 89 4C 24 ? ? ? 5A 22")
DEFINE(Sigs::networkitemstackdescriptor::fromStack, "48 89 5C 24 ? 55 56 57 41 56 41 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 48 8B FA 48 8B F1 48 89 4C 24 ? 0F B6 ? ? 48 8D 54 24 ? 48 8B CF")
//ContainerScreenController
DEFINE(Sigs::ContainerScreenController::ContainerScreenController__handleAutoPlace, "40 55 53 56 57 41 54 41 55 41 56 41 57 48 8d ac 24 ? ? ? ? 48 81 ec ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 85 ? ? ? ? 45 8b e1 49 8b f0 44 8b fa")
DEFINE(Sigs::ContainerScreenController::ContainerScreenController__handleDropItem, "48 89 5c 24 ? 55 56 57 41 56 41 57 48 83 ec ? 4d 8b f1 45 8b f8");
DEFINE(Sigs::ContainerScreenController::ContainerScreenController__handlePlaceAll, "48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 56 48 83 ec ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 44 24 ? 41 8b e8 48 8b fa");
DEFINE(Sigs::ContainerScreenController::ContainerScreenController__handleTakeAll, "48 89 5c 24 ? 48 89 6c 24 ? 48 89 74 24 ? 48 89 7c 24 ? 41 56 48 83 ec ? 45 8b f0 48 8b fa");
DEFINE(Sigs::ContainerScreenController::ContainerScreenController_tick, "48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 56 48 83 ec ? 0f 29 74 24 ? 48 8b f1");
//InventoryTransactionManager
DEFINE(Sigs::inventorytransactionmanager::addAction, "40 53 55 41 56 48 83 EC ? 48 8B 01 48 8B D9")
//itemstack
DEFINE(Sigs::Itemstack::Dropslot,"85 d2 0f 88 ? ? ? ? 48 89 5c 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8d ac 24")
DEFINE(Sigs::Itemstack::Emptyitemstack, "48 8d 35 ? ? ? ? 80 ba ? ? ? ? ? 75 ? 48 8b 8a ? ? ? ? 48 8b 01")
//hook
DEFINE(Sigs::hook::GetFogColorHook, "41 0f 10 08 48 8b c2 0f 28 d3")
DEFINE(Sigs::hook::ShouldRender, "48 83 ec ? 48 8b 01 48 8b 80 ? ? ? ? ff 15 ? ? ? ? 84 c0 0f 94 c0 48 83 c4 ? c3 cc cc 40 53")
DEFINE(Sigs::hook::KeyMapHook, "48 ? ? 48 ? ? ? 4C 8D 05 ? ? ? ? 89")
DEFINE(Sigs::hook::KeyMouseHook, "48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 57 41 54 41 55 41 56 41 57 48 83 EC ? 44 0F B7 BC 24 ? ? ? ? 48 8B D9")
DEFINE(Sigs::hook::HurtColorHook, "E8 ? ? ? ? E9 ? ? ? ? 8B 43 18 89 44 24 ? 48 8D 54 24 ? 48 8B 4B ? E8 ? ? ? ? 48 8B F8")
DEFINE(Sigs::hook::CameraNoClip, "F3 44 0F 51 EA 45 0F 28 CD")
DEFINE(Sigs::hook::HIDControllerHook, "48 8B C4 48 89 58 10 55 56 57 41 54 41 55 41 56 41 57 48 8D 68 A1 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 FF")
DEFINE(Sigs::hook::GetGammaHook, "48 83 EC ? 80 B9 ? ? ? ? ? 48 8D 54 24 ? 48 8B 01 48 8B 40 ? 74 ? 41 B8 ? ? ? ? FF 15 ? ? ? ? 48 8B 10 48 85 D2 74 ? 48 8B 42 ? 48 8B 88 ? ? ? ? 48 85 C9 74 ? E8 ? ? ? ? 48 83 C4 ? C3 F3 0F 10 42 ? 48 83 C4 ? C3 41 B8 ? ? ? ? FF 15 ? ? ? ? 48 8B 10 48 85 D2 75 ? E8 ? ? ? ? CC E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC F3 0F 11 4C 24")
DEFINE(Sigs::hook::ActorLerpMotionHook, "48 8B CB 48 8B 80 ? ? ? ? FF 15 ? ? ? ? C6 46 ? ? 48 8B 5C 24")
DEFINE(Sigs::hook::SetupAndRenderHook, "48 8B C4 48 89 58 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA")
DEFINE(Sigs::hook::FontDrawTransformedHook, "48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 48 89 78 ? 41 54 41 56 41 57 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78")
DEFINE(Sigs::hook::GetCurrentSwingDurationHook, "48 89 5C 24 ? 57 48 83 EC 20 48 8B 15 ? ? ? ? 48 8B F9 33 DB")
DEFINE(Sigs::hook::ServerTickBlockBreakingHook, "48 89 5C 24 ? 55 56 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 ? ? ? ? 41 8B E8 48 8B F2 48 8B F9 48")
DEFINE(Sigs::hook::CauseHurtHook, "40 53 55 57 41 56 48 83 EC 38 41")
DEFINE(Sigs::hook::RenderLevelHook, "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 49 8B F0 48 8B DA 4C");
DEFINE(Sigs::hook::getFovHook, "48 8B C4 48 89 58 18 48 89 70 20 57 48 81 EC ? ? ? ? 0F 29 70 E8 0F 29 78 D8 44 0F 29 40 ? 44 0F 29 48 ? 48 8B 05 ? ? ? ? 48");
DEFINE(Sigs::hook::ItemUseSlowdownSystemImpl_doItemUseSlowdownSystemHook, "48 89 5C 24 ? 57 48 83 EC 30 49 8B D8 4D 85 C9")
DEFINE(Sigs::hook::MobJumpFromGroundSystemImpl_mobJumpFromGroundHook, "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 48 8B BC 24")

//vtable
DEFINE(Sigs::vtable::PlayerVtable, "48 8D 05 ? ? ? ? 48 89 01 B8 ? ? ? ? 8D 50 FA 44 8D 48 ? 44 8D 40 ? 66 89 44 ? ? E8 ? ? ? ? 48 8B 8B")
DEFINE(Sigs::vtable::GamemodeVtable, "48 8D 05 ? ? ? ? 48 89 01 48 89 51 08 48 C7 41 ? ? ? ? ? C7 41 ? ? ? ? ?")

// global
DEFINE(Sigs::global::survivalReach, "F3 ? ? 05 ? ? ? ? 44 ? ? F8 76 09")

//component
DEFINE(Sigs::component::getActorTypeComponent, "E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 8B 10 45")
DEFINE(Sigs::component::getFallDistanceComponent, "E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? F3 0F 11 30 48 8D 05")
DEFINE(Sigs::component::getRenderPositionComponent, "E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? F3 0F 10 85 ? ? ? ? F3 0F 11 00 F3")
DEFINE(Sigs::component::getMobBodyRotationComponent, "e8 ? ? ? ? ba ? ? ? ? 49 8b cf 4c 8b e0 e8 ? ? ? ? ba ? ? ? ? 49 8b cf 4c 8b f0 e8 ? ? ? ? ba ? ? ? ? 49 8b cf 48 8b e8 e8 ? ? ? ? ba ? ? ? ? 49 8b cf 48 8b f0 e8 ? ? ? ? ba ? ? ? ? 49 8b cf 48 8b f8 e8 ? ? ? ? ba ? ? ? ? 49 8b cf 48 8b d8 e8 ? ? ? ? 48 8b 8c 24 ? ? ? ? 4d 8b ce 48 89 44 24 ? 4d 8b c4 48 89 5c 24 ? 49 8b d5 48 89 7c 24 ? 48 89 74 24 ? 48 89 6c 24 ? e8 ? ? ? ? 48 8b 84 24 ? ? ? ? 4c 8d 5c 24 ? 49 8b 5b ? 49 8b 6b ? 49 8b 73 ? 49 8b e3 41 5f 41 5e 41 5d 41 5c 5f c3 cc cc cc cc cc cc cc cc cc cc cc cc cc 48 89 5c 24 ? 57")
DEFINE(Sigs::component::getMobEffectsComponent, "E8 ? ? ? ? 48 85 C0 74 34 4C 8B 00 8B D3")
DEFINE(Sigs::component::onGroundFlag, "e8 ? ? ? ? ba ? ? ? ? 49 8b cd 48 8b f8 e8 ? ? ? ? ba ? ? ? ? 49 8b cd 48 8b d8 e8 ? ? ? ? 4c 8b 84 24 ? ? ? ? 4d 8b cc 48 8b 54 24 ? 48 8b 8c 24 ? ? ? ? 48 89 44 24 ? 48 89 5c 24 ? 48 89 7c 24 ? 48 89 74 24 ? 48 89 6c 24 ? 4c 89 74 24 ? 4c 89 7c 24 ? e8 ? ? ? ? 48 8b 84 24 ? ? ? ? 48 8b 9c 24 ? ? ? ? 48 83 c4 ? 41 5f 41 5e 41 5d 41 5c 5f 5e 5d c3 cc cc cc 48 89 5c 24 ? 57 48 81 ec ? ? ? ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 44 24 ? 48 8b da 48 8b f9 48 89 4c 24 ? 48 89 54 24 ? e8 ? ? ? ? 48 8b c8 48 8b 00 ba ? ? ? ? 48 8b 40 ? ff 15 ? ? ? ? 48 85 c0 75 ? 48 c7 44 24 ? ? ? ? ? 48 8d 05 ? ? ? ? 48 89 44 24 ? 4c 8d 0d ? ? ? ? 41 b8 ? ? ? ? 48 8d 15 ? ? ? ? 48 8d 0d ? ? ? ? e8 ? ? ? ? 84 c0 74 ? c7 04 25 ? ? ? ? ? ? ? ? 33 c0 eb ? 48 8d 0d ? ? ? ? 48 89 08 48 c7 44 24 ? ? ? ? ? 48 89 07 0f 10 03 0f 11 44 24 ? 0f 10 4b ? 0f 11 4c 24 ? 48 c7 43 ? ? ? ? ? 48 c7 43 ? ? ? ? ? c6 03 ? 48 8d 4f ? 48 8d 54 24 ? e8 ? ? ? ? 90 48 8b cb e8 ? ? ? ? 48 8b c7 48 8b 4c 24 ? 48 33 cc e8 ? ? ? ? 48 8b 9c 24 ? ? ? ? 48 81 c4 ? ? ? ? 5f c3 cc cc cc cc cc cc cc cc cc cc cc 48 89 5c 24 ? 48 89 74 24")
DEFINE(Sigs::component::getActorUniqueIDComponent, "e8 ? ? ? ? ba ? ? ? ? 48 8b cd 4c 8b f0 e8 ? ? ? ? ba ? ? ? ? 48 8b cd 48 8b f0 e8 ? ? ? ? ba ? ? ? ? 48 8b cd 48 8b f8 e8 ? ? ? ? ba ? ? ? ? 48 8b cd 48 8b d8 e8 ? ? ? ? 49 89 04 24 49 8d 54 24 ? 49 89 7c 24 ? 49 8d 4c 24 ? 48 89 1a 4d 8d 4c 24 ? 49 89 31 4d 8d 44 24 ? 4d 89 30 33 c0 4d 89 7c 24 ? 49 89 44 24 ? 49 8b 44 24 ? 4c 89 64 24 ? 48 89 54 24 ? 48 89 4c 24 ? 48 8d 4c 24 ? 49 89 44 24 ? 4c 89 64 24 ? e8 ? ? ? ? 48 8b 5c 24 ? 49 8b c4 48 8b ac 24 ? ? ? ? 48 83 c4 ? 41 5f 41 5e 41 5c 5f 5e c3 cc cc cc 48 89 5c 24 ? 48 89 74 24 ? 57 48 83 ec ? 48 8d 05 ? ? ? ? 49 8b f8 48 89 44 24 ? 48 8b d9 e8 ? ? ? ? 48 8b f0 48 89 5c 24 ? 48 8d 44 24 ? 48 89 7c 24 ? 48 89 44 24 ? 48 8b 46 ? 48 85 c0 0f 84 ? ? ? ? 48 39 46 ? 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 46 ? 48 39 46 ? 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 46 ? 48 39 46 ? 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 46 ? 48 39 46 ? 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 46 ? 48 39 46 ? 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 46 ? 48 39 06 75 ? 48 8d 54 24 ? 48 8b ce e8 ? ? ? ? 48 8b 5c 24 ? 48 8b 74 24 ? 48 83 c4 ? 5f c3 cc 48 89 5c 24 ? 57")