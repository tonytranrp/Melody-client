#pragma once
#define PI (3.1415927f)
#include <algorithm>
#include <cmath>
#include "../Libs/ImGui/imgui.h"
#include <math.h>
#include <stdexcept>
#include <string>
static constexpr float DEG_RAD2 = PI / 360.0f;
static constexpr float DEG_RAD = 180.0f / PI;
static constexpr float RAD_DEG = PI / 180.f;

template<typename T>
struct Vec2 {

	union {
		struct {
			T x, y;
		};
		T arr[2];
	};

	Vec2(T x = 0, T y = 0) {
		this->x = x; this->y = y;
	}

	ImVec2 toImVec2() {
		return ImVec2((float)x, (float)y);
	}

	Vec2<T> add(const Vec2<T>& v2) {
		return Vec2<T>(this->x + v2.x, this->y + v2.y);
	}

	Vec2<T> add(T o) {
		return Vec2<T>(this->x + o, this->y + o);
	}

	Vec2<T> sub(const Vec2<T> v2) {
		return Vec2<T>(this->x - v2.x, this->y - v2.y);
	}
	Vec2<T> mul(float a, float b) {
		return Vec2<T>(x * a, y * b);
	}

	Vec2<T> mul(const Vec2<T>& v3) {
		return Vec2<T>(x * v3.x, y * v3.y);
	}

	Vec2<T> mul(float a) {
		return Vec2<T>(x * a, y * a);
	}
	Vec2<T> sub(const Vec2<int>& o) {
		return Vec2<T>(x - o.x, y - o.y);
	}
	Vec2<T> operator+(const Vec2<T>& v2) const {
		return Vec2<T>(this->x + v2.x, this->y + v2.y);
	}

	Vec2<T> operator*(const T& scalar) const {
		return Vec2<T>(this->x * scalar, this->y * scalar);
	}
};

template<typename T>
struct Vec3 {

	union {
		struct {
			T x, y, z;
		};
		T arr[3];
	};

	Vec3<T>(T x = 0, T y = 0, T z = 0) {
		this->x = x; this->y = y; this->z = z;
	}

	Vec3<T>(const Vec3<T>& copy) {
		this->x = copy.x; this->y = copy.y; this->z = copy.z;
	}

	bool operator != (const Vec3<T>& v3) {
		return v3.x != x || v3.y != y || v3.z != z;
	};
	bool operator==(const Vec3<T>& v3) const {
		return v3.x == x && v3.y == y && v3.z == z;
	}
	bool operator*(const Vec3<T>& v3) const {
		return v3.x * x && v3.y * y && v3.z * z;
	}
	bool operator+(const Vec3<T>& v3) const {
		return v3.x + x && v3.y + y && v3.z + z;
	}
	Vec3<T> add(float a) {
		return Vec3<T>(x + a, y + a, z + a);
	}
	Vec3<T> add(float a, float b, float c) {
		return Vec3<T>(x + a, y + b, z + c);
	}
	template<typename R> float distanceTo(const Vec3<R>& other) const { return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) + pow(other.z - this->z, 2)); }
	Vec3<T> add(const Vec3<T>& v3) {
		return Vec3<T>(x + v3.x, y + v3.y, z + v3.z);
	}
	
	Vec3<T> mul(float a, float b, float c) {
		return Vec3<T>(x * a, y * b, z * c);
	}

	Vec3<T> mul(const Vec3<T>& v3) {
		return Vec3<T>(x * v3.x, y * v3.y, z * v3.z);
	}

	Vec3<T> sub(const Vec3<int>& o) {
		return Vec3<T>(x - o.x, y - o.y, z - o.z);
	}

	Vec3<T> sub(const Vec3<float>& o) {
		return Vec3<T>(x - o.x, y - o.y, z - o.z);
	}
	Vec3<T> operator-(const Vec3<int>& o) {
		return Vec3<T>(x - o.x, y - o.y, z - o.z);
	}

	Vec3<T> operator-(const Vec3<float>& o) {
		return Vec3<T>(x - o.x, y - o.y, z - o.z);
	}
	Vec3<T> floor() {
		return Vec3<T>(floorf(x), floorf(y), floorf(z));
	}

	Vec3<int> toInt() {
		return Vec3<int>((int)x, (int)y, (int)z);
	}

	Vec3<float> toFloat() {
		return Vec3<float>((float)x, (float)y, (float)z);
	}

	float dist(const Vec3<int>& e) {
		return sub(e).magnitude();
	}

	float dist(const Vec3<float>& e) {
		return sub(e).magnitude();
	}

	Vec3<T> lerp(const Vec3<float>& o, float val) {
		Vec3<float> ne;
		ne.x = x + val * (o->x - x);
		ne.y = y + val * (o->y - y);
		ne.z = z + val * (o->z - z);
		return ne;
	};

	Vec3<T> lerp(const Vec3<float>& o, float tx, float ty, float tz) {
		Vec3<float> ne;
		ne.x = x + tx * (o.x - x);
		ne.y = y + ty * (o.y - y);
		ne.z = z + tz * (o.z - z);
		return ne;
	};

	float squaredlen() {
		return x * x + y * y + z * z;
	}

	float squaredxzlen() {
		return x * x + z * z;
	}

	T magnitude() const { return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)); };

	Vec2<float> CalcAngle(Vec3<float> dst) {
		Vec3<float> diff = dst.sub(*this);

		diff.y = diff.y / diff.magnitude();
		Vec2<float> angles;
		angles.x = asinf(diff.y) * -DEG_RAD;
		angles.y = (float)-atan2f(diff.x, diff.z) * DEG_RAD;

		return angles;
	}
	Vec3<T> normalize() const { float mag = this->magnitude(); return Vec3<T>(this->x / mag, this->y / mag, this->z / mag); }
};

struct AABB {
	Vec3<float> lower;
	Vec3<float> upper;
	Vec2<float> size;

	bool intersects(AABB aabb) {
		return aabb.upper.x > lower.x && upper.x > aabb.lower.x &&
			aabb.upper.y > lower.y && upper.y > aabb.lower.y &&
			aabb.upper.z > lower.z && upper.z > aabb.lower.z;
	}

};

template<typename T>
struct Vec4 {

	union {
		struct {
			T x, y, z, w;
		};
		T arr[4];
	};

	Vec4(T x = 0, T y = 0, T z = 0, T w = 0) {
		this->x = x; this->y = y; this->z = z; this->w = w;
	}

	__forceinline bool contains(const Vec2<float>& point) {
		if (point.x <= x || point.y <= y)
			return false;

		if (point.x >= z || point.y >= w)
			return false;
		return true;
	};
};

struct glmatrixf {
	union {
		float v[16];
		float v_nested[4][4];
	};

	__forceinline float operator[](int i) const { return v[i]; }
	__forceinline float& operator[](int i) { return v[i]; }

#define MULMAT(row, col) v[col + row] = x[row] * y[col] + x[row + 4] * y[col + 1] + x[row + 8] * y[col + 2] + x[row + 12] * y[col + 3];

	template <class XT, class YT>
	void mul(const XT x[16], const YT y[16]) {
		MULMAT(0, 0);
		MULMAT(1, 0);
		MULMAT(2, 0);
		MULMAT(3, 0);
		MULMAT(0, 4);
		MULMAT(1, 4);
		MULMAT(2, 4);
		MULMAT(3, 4);
		MULMAT(0, 8);
		MULMAT(1, 8);
		MULMAT(2, 8);
		MULMAT(3, 8);
		MULMAT(0, 12);
		MULMAT(1, 12);
		MULMAT(2, 12);
		MULMAT(3, 12);
	}

#undef MULMAT

	glmatrixf* correct() {
		glmatrixf* newMatPtr = new glmatrixf;

		for (int i = 0; i < 4; i++) {
			newMatPtr->v[i * 4 + 0] = v[0 + i];
			newMatPtr->v[i * 4 + 1] = v[4 + i];
			newMatPtr->v[i * 4 + 2] = v[8 + i];
			newMatPtr->v[i * 4 + 3] = v[12 + i];
		}
		return newMatPtr;
	};

	inline bool OWorldToScreen(const Vec3<float>& origin, Vec3<float> pos, Vec2<float>& screen, Vec2<float> fov, Vec2<float> displaySize) {
		pos = pos.sub(origin);

		float x = transformx(pos);
		float y = transformy(pos);
		float z = transformz(pos);

		if (z > 0)
			return false;

		float mX = (float)displaySize.x / 2.0F;
		float mY = (float)displaySize.y / 2.0F;

		screen.x = mX + (mX * x / -z * fov.x);
		screen.y = mY - (mY * y / -z * fov.y);

		return true;
	}

	__forceinline float transformx(const Vec3<float>& p) const {
		return p.x * v[0] + p.y * v[4] + p.z * v[8] + v[12];
	}

	__forceinline float transformy(const Vec3<float>& p) const {
		return p.x * v[1] + p.y * v[5] + p.z * v[9] + v[13];
	}

	__forceinline float transformz(const Vec3<float>& p) const {
		return p.x * v[2] + p.y * v[6] + p.z * v[10] + v[14];
	}
};

class Math {
public:
	inline static float lerp(float endPoint, float current, float speed) {
		if (speed < 0.0) speed = 0.0;
		else if (speed > 1.0) speed = 1.0;

		float dif = std::max(endPoint, current) - std::min(endPoint, current);
		float factor = dif * speed;
		return current + (endPoint > current ? factor : -factor);
	}
	inline static float calculateDistance(const Vec3<float>& vec) {
		return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}
	inline static int random(int start, int end) {
		return rand() % (end - start + 1) + start;
	}
};
