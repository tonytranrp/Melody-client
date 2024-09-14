#pragma once
#include "../../Utils/MemoryUtils.h"
#include "../../Utils/Math.h"

#include "ItemStack.h"
#include "ComplexInventoryTransaction.h"
enum class PacketID : int32_t {
	Text = 9,
	MoveEntityAbsolutePacket = 0x12,
	InventoryTransaction = 30,
	MovePlayerPacket = 0x13,
	MobEquipmentPacket = 0x1F,
	Interact = 0x21,
	EntityFallPacket = 0x25,
	ContainerOpenPacket = 0x2e,
	ContainerClosePacket = 0x2f,
	PlayerInputPacket = 0x39,
	ChangeDimensionPacket = 0x3D,
	TransferPacket = 0x55,
	MoveEntityDeltaPacket = 0x6F,
	NetworkStackLatencyPacket = 0x73,
	LevelSoundEvent = 0x7b,
	PlayerAuthInput = 0x90,
	ItemStackRequestPacket = 0x93,
	PacketViolationWarning = 0x9C,
};

class Packet {
private:
	char pad_0x0[0x30]; // 0x0
public:
	PacketID getId() {
		return MemoryUtils::CallVFunc<1, PacketID>(this);
	}
	std::string getName() {
		return *MemoryUtils::CallVFunc<2, std::string*>(this, std::string());
	}
};

class TextPacket : public Packet {
public:
	/*
	enum class Type : int8_t {
		Raw = 0,
		Chat = 1,
		Translate = 2,
		Popup = 3,
		JukeboxPopup = 4,
		Tip = 5,
		SystemMessage = 6,
		Whisper = 7,
		Announcement = 8,
		TextObjectWhisper = 9,
		TextObject = 10,
	};
	*/
	int8_t messageType;
	std::string userName;
	std::string message;
private:
	char pad[0x18];
public:
	bool translationNeeded = false;
};
/*playerauth field */
enum class AuthInputAction : uint64_t
{
	// Movement
	ASCEND = 1ULL << 0,
	DESCEND = 1ULL << 1,
	NORTH_JUMP = 1ULL << 2,
	JUMP_DOWN = 1ULL << 3,
	SPRINT_DOWN = 1ULL << 4,
	CHANGE_HEIGHT = 1ULL << 5,
	JUMPING = 1ULL << 6,
	AUTO_JUMPING_IN_WATER = 1ULL << 7,
	SNEAKING = 1ULL << 8,
	SNEAK_DOWN = 1ULL << 9,
	SPRINTING = 1ULL << 20,

	// Directional movement
	UP = 1ULL << 10,
	DOWN = 1ULL << 11,
	LEFT = 1ULL << 12,
	RIGHT = 1ULL << 13,
	UP_LEFT = 1ULL << 14,
	UP_RIGHT = 1ULL << 15,

	// Vertical movement preferences
	WANT_UP = 1ULL << 16,
	WANT_DOWN = 1ULL << 17,
	WANT_DOWN_SLOW = 1ULL << 18,
	WANT_UP_SLOW = 1ULL << 19,

	// Scaffold movement
	ASCEND_SCAFFOLDING = 1ULL << 21,
	DESCEND_SCAFFOLDING = 1ULL << 22,

	// Sneak and sprint toggles
	SNEAK_TOGGLE_DOWN = 1ULL << 23,
	PERSIST_SNEAK = 1ULL << 24,
	START_SPRINTING = 1ULL << 25,
	STOP_SPRINTING = 1ULL << 26,
	START_SNEAKING = 1ULL << 27,
	STOP_SNEAKING = 1ULL << 28,

	// Swimming actions
	START_SWIMMING = 1ULL << 29,
	STOP_SWIMMING = 1ULL << 30,

	// Jumping and gliding
	START_JUMPING = 1ULL << 31,
	START_GLIDING = 1ULL << 32,
	STOP_GLIDING = 1ULL << 33,

	// Item and block interactions
	PERFORM_ITEM_INTERACTION = 1ULL << 34,
	PERFORM_BLOCK_ACTIONS = 1ULL << 35,
	PERFORM_ITEM_STACK_REQUEST = 1ULL << 36,

	// Teleport and emoting
	HANDLE_TELEPORT = 1ULL << 37,
	EMOTING = 1ULL << 38
};


inline AuthInputAction operator|(AuthInputAction a, AuthInputAction b) {
	return static_cast<AuthInputAction>(static_cast<uint64_t>(a) | static_cast<uint64_t>(b));
}

inline AuthInputAction operator&(AuthInputAction a, AuthInputAction b) {
	return static_cast<AuthInputAction>(static_cast<uint64_t>(a) & static_cast<uint64_t>(b));
}

inline AuthInputAction operator^(AuthInputAction a, AuthInputAction b) {
	return static_cast<AuthInputAction>(static_cast<uint64_t>(a) ^ static_cast<uint64_t>(b));
}

inline AuthInputAction operator~(AuthInputAction a) {
	return static_cast<AuthInputAction>(~static_cast<uint64_t>(a));
}

inline void operator|=(AuthInputAction& a, AuthInputAction b) {
	a = a | b;
}

inline void operator&=(AuthInputAction& a, AuthInputAction b) {
	a = a & b;
}

inline void operator^=(AuthInputAction& a, AuthInputAction b) {
	a = a ^ b;
}

inline bool operator!(AuthInputAction a) {
	return static_cast<uint64_t>(a) == 0;
}

enum class ClientPlayMode {
	NORMAL,
	TEASER,
	SCREEN,
	VIEWER,
	REALITY,
	PLACEMENT,
	LIVING_ROOM,
	EXIT_LEVEL,
	EXIT_LEVEL_LIVING_ROOM
};
enum class LnputMode : int {
	UNDEFINED = 0,
	MOUSE = 1,
	TOUCH = 2,
	GAME_PAD = 3,
	MOTION_CONTROLLER = 4,
	COUNT = 5
};
class PlayerAuthInputPacket : public Packet {
public:
	/* Fields */
	Vec2<float> rotation; //0x0030
	Vec3<float> position; //0x0038
	float headYaw; //0x0044
	char pad_0048[4]; //0x0048
	float downVelocity; //0x004C
	char pad_0050[32]; //0x0050
	AuthInputAction inputData; //0x0070
	LnputMode inputMode; //0x0078
	ClientPlayMode playMode; //0x007C
	char pad_0080[8]; //0x0080
	int32_t ticksAlive; //0x0088
	char pad_008C[44]; //0x008C
};
enum class InteractAction
{
	RIGHT_CLICK = 1,
	LEFT_CLICK = 2,
	LEAVE_VEHICLE = 3,
	MOUSEOVER = 4
};
class InteractPacket : public Packet {
public:

	InteractPacket(InteractAction action, uint64_t actorRuntimeID, Vec3<float> interactPos) {
		memset(this, 0x0, sizeof(InteractPacket));
		using InteractPacketConstructor_t = void(__fastcall*)(InteractPacket*, InteractAction, uint64_t, Vec3<float>&);
		static InteractPacketConstructor_t InteractPacketConstructor = (InteractPacketConstructor_t)(findSig(Sigs::packet::InteractPacket_cctor));
		InteractPacketConstructor(this, action, actorRuntimeID, interactPos);
	}
public:
	int8_t action; //0x0030
	uint64_t actorRuntimeID; //0x0038
	Vec3<float> interactPos; //0x0040
private:
	char pad_004C[4]{}; //0x004C
	char pad_003C[4]{}; //0x003C
	char pad_0031[7]{}; //0x0031
};
class MobEquipmentPacket : public Packet {
public:
	MobEquipmentPacket(uint64_t runtimeId, ItemStack* itemStack, int hotbarSlot, int inventorySlot) {
		memset(this, 0x0, sizeof(MobEquipmentPacket));
		using MobEquipmentPacketConstructor_t = void(__fastcall*)(MobEquipmentPacket*, uint64_t, ItemStack*, int, int, char);
		static  MobEquipmentPacketConstructor_t  MobEquipmentPacketConstructor = (MobEquipmentPacketConstructor_t)(findSig(Sigs::packet::ModEquipmentPacket));
		MobEquipmentPacketConstructor(this, runtimeId, itemStack, hotbarSlot, inventorySlot, 0);
	}

	uint64_t entityRuntimeId; // 0x30
	__int64 item; // 0x38
private:
	char pad_0x40[0x58];  // 0x40
public:
	int hotbarSlot; // 0x98
	int inventorySlot; // 0x9C
	char windowId; // 0xA0
	char hotbarSlotByte; // 0xA1
	char inventorySlotByte; // 0xA2
	char windowIdByte; // 0xA3
	// fully reversed by TrongDiZep <3
};

class AnimatePacket : public Packet {
	//48 89 5C 24 10 48 89 74 24 20 48 89 4C 24 08 57 48 83 EC 20 8B FA 48 8B D9
public:
	AnimatePacket(int action, uint64_t entityRuntimeID) {
		memset(this, 0x0, sizeof(AnimatePacket));
		using AnimatePacketConstructor_t = void(__fastcall*)(AnimatePacket*, int, uint64_t);
		static AnimatePacketConstructor_t  AnimatePacketConstructor = (AnimatePacketConstructor_t)(findSig(Sigs::packet::AnimatePacket));
		AnimatePacketConstructor(this, action, entityRuntimeID);
	}
public:
	int unknown;
	int action;
	float uh; // this = 0 
};
class EmotePacket : public Packet {
public:
	uint64_t runtimeId;
	std::string prettifiedEmoteUuid;
	uint8_t flags;
};

class MobEffectPacket : public Packet {
public:
	MobEffectPacket(uint64_t entityRuntimeId, char event, int effectId, int amplifier, bool showParticles, int duration) {
		memset(this, 0x0, sizeof(MobEffectPacket));
		using MobEffectPacketConstructor_t = void(__fastcall*)(MobEffectPacket*, uint64_t, char, int, int, bool, int);
		static MobEffectPacketConstructor_t  constructor = (MobEffectPacketConstructor_t)(findSig(Sigs::packet::MobEffectPacket));
		constructor(this, entityRuntimeId, event, effectId, amplifier, showParticles, duration);
	}
public:
	uint64_t entityRuntimeId;
	char event;
	int effectId;
	int amplifier;
	bool showParticles;
	int duration;
};

class InventoryTransactionPacket : public Packet {
public:
	InventoryTransactionPacket(ComplexInventoryTransaction* transaction, bool isClientSide) {
		memset(this, 0x0, sizeof(InventoryTransactionPacket));
		using constructor_t = void(__fastcall*)(InventoryTransactionPacket*, ComplexInventoryTransaction*, bool);
		static constructor_t  constructor = (constructor_t)(findSig(Sigs::packet::InventoryTransactionPacket));
		constructor(this, transaction, isClientSide);
	}
private:
	char pad_0x30[0x28];
public:
	std::unique_ptr<ComplexInventoryTransaction> transaction; // 0x58
	bool isClientSide; // 0x60
	//40 53 48 83 EC ? 45 33 C9 C7 41 08 ? ? ? ?
};

class MovePlayerPacket : public Packet {
public:
	MovePlayerPacket(Player* player, Vec3<float> position) {
		memset(this, 0x0, sizeof(MovePlayerPacket));
		using constructor_t = void(__fastcall*)(MovePlayerPacket*, Player*, Vec3<float>*);
		static constructor_t  constructor = (constructor_t)(findSig(Sigs::packet::MovePlayerPacket));
		constructor(this, player, &position);
	}
public:
	int64_t actorRuntimeID;
	Vec3<float> position;
	Vec2<float> rotation;
	float headYaw;
	uint8_t mode;
	bool onGround;
	uint64_t ridingRuntimeId;
	int teleportCause;
	__int32 teleportItem;
	__int32 tick;
	//48 89 5C 24 08 57 48 83 EC ? B9 ? ? ? ? E8 ? ? ? ?
};