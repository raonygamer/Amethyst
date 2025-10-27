#pragma once
#include <mc/src/common/world/phys/Vec2.hpp>
#include <mc/src/common/world/phys/Vec3.hpp>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace mce {
    class Math {
    public:
        template <typename T>
        static constexpr size_t hash_accumulate(size_t hash, const T& toHash)
        {
            return ((hash >> 2) + (hash << 6) + std::hash<T>{}(toHash) + 0x9E3779B9u) ^ hash;
        }

        static constexpr size_t hash_accumulate_hashed(size_t hash, size_t other)
        {
            return ((hash >> 2) + (hash << 6) + other + 0x9E3779B9u) ^ hash;
        }

        static float sin(float x)
        {
            return std::sin(x);
        }

        static float cos(float x)
        {
            return std::cos(x);
        }

        static float tan(float x)
        {
            return std::tan(x);
        }

        static float asin(float x)
        {
            return std::asin(x);
        }

        static float acos(float x)
        {
            return std::acos(x);
        }

        static float atan(float x)
        {
            return std::atan(x);
        }

        static float atan2(float y, float x)
        {
            return std::atan2(y, x);
        }

        static float sqrt(float x)
        {
            return std::sqrt(x);
        }

        static Vec3 quaternionToViewVector(const glm::quat& q)
        {
            return glm::rotate(q, glm::vec3(0.0f, 0.0f, -1.0f));
        }

        static Vec2 viewVectorToRotation(const Vec3& normLook)
        {
            float hDist = normLook.lengthXZ();
            float yaw = glm::degrees(std::atan2(normLook.z, normLook.x)) - 90.0f;
            float pitch = -glm::degrees(std::atan2(normLook.y, hDist));
            return Vec2(pitch, yaw);
        }

        static Vec3 rotationToViewVector(const Vec2& rotation)
        {
            float pitch = glm::radians(rotation.x);
            float yaw = glm::radians(rotation.y);

            float x = std::cos(pitch) * std::cos(yaw + glm::half_pi<float>());
            float y = std::sin(-pitch);
            float z = std::cos(pitch) * std::sin(yaw + glm::half_pi<float>());

            return Vec3(x, y, z);
        }
        
        static float wrapRadians(float angle)
        {
            angle = fmod(angle, glm::two_pi<float>());
            if (angle >= glm::pi<float>())
                angle -= glm::two_pi<float>();
            if (angle < -glm::pi<float>())
                angle += glm::two_pi<float>();
            return angle;
        }
    };
};