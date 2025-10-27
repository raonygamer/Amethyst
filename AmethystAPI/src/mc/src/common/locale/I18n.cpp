#include "mc/src/common/locale/I18n.hpp"
#include <amethyst/Memory.hpp>
#include "I18n.hpp"

std::string operator""_i18n(const char* str, size_t)
{
    return getI18n().get(str, nullptr);
}

std::string i18n(const std::string& key) {
    return getI18n().get(key, nullptr);
}