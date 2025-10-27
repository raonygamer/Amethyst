#pragma once
#include <format>
#include <glm/vec3.hpp>

class BlockPos;

class Vec3 {
public:
    float x;
    float y;
    float z;

public:
    Vec3();
    Vec3(float x, float y, float z);
    Vec3(const BlockPos&);
    Vec3(const glm::vec3&);

    Vec3 operator+(const Vec3 rhs) const;
    Vec3 operator-(const Vec3 rhs) const;
    Vec3 operator*(const Vec3 rhs) const;
    Vec3 operator*(float rhs) const;
    Vec3 operator/(const Vec3 rhs) const;
    bool operator==(const Vec3 rhs) const;

	Vec3& operator=(const Vec3& rhs);

    void rotateAroundXRadians(float angleRadians);
    void rotateAroundYRadians(float angleRadians);
    void rotateAroundZRadians(float angleRadians);
    void rotateAroundPointRadians(const Vec3& pivot, const Vec3& angle);

    void rotateAroundXDegrees(float angleDegrees);
    void rotateAroundYDegrees(float angleDegrees);
    void rotateAroundZDegrees(float angleDegrees);
    void rotateAroundPointDegrees(const Vec3& pivot, const Vec3& angle);

    float distance(const Vec3& other) const;

    float lengthXZ() const;

	float dot(const Vec3& v) const {
		return x * v.x + y * v.y + z * v.z;
	}

	Vec3 cross(const Vec3& v) const {
		return {
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		};
	}

	float lengthSquared() const {
		return x * x + y * y + z * z;
	}

	float length() const {
		return std::sqrt(lengthSquared());
	}

	Vec3 normalized() const {
		float len = length();
		if (len < 1e-6f) return { 0, 0, 0 };
		return { x / len, y / len, z / len };
	}


    static Vec3 lerp(const Vec3& start, const Vec3& end, float t);
    static Vec3 ZERO;

    operator glm::vec3() const
    {
        return glm::vec3(x, y, z);
    }
};

// BinaryStream specialization
#include "mc/src-deps/core/utility/BinaryStream.hpp"

template <>
Bedrock::Result<Vec3> ReadOnlyBinaryStream::get<Vec3>();

template <>
void BinaryStream::write(Vec3);

template <>
struct std::formatter<Vec3> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const Vec3& pos, FormatContext& ctx) const {
        return std::format_to(ctx.out(), "Vec3(x: {}, y: {}, z: {})", pos.x, pos.y, pos.z);
    }
};