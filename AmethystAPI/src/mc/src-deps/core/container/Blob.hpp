#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>
#include <algorithm>

namespace mce {

    class Blob {
    public:
        using size_type = std::size_t;
        using value_type = uint8_t;
        using iterator = value_type*;
        using delete_function = void (*)(value_type*);

        struct Deleter {
            delete_function m_func;

            Deleter() : m_func(nullptr) {}
            explicit Deleter(delete_function func) : m_func(func) {}

            void operator()(value_type* ptr) const noexcept {
                if (m_func) {
                    m_func(ptr);
                } else {
                    delete[] ptr;
                }
            }

            delete_function getDeleteFunc() const noexcept {
                return m_func;
            }
        };

        using pointer_type = std::unique_ptr<value_type[], Deleter>;

    private:
        pointer_type mBlob;
        size_type mSize;

    public:
        // Constructors
        Blob();
        Blob(const iterator data, size_type size);
        Blob(const Blob& other);
        Blob(Blob&& other) noexcept;
		Blob(size_type size);

        // Assignment operators
        Blob& operator=(const Blob& other);
        Blob& operator=(Blob&& other) noexcept;

        // Accessors
        size_type size() const noexcept;
        iterator data() noexcept;
        const iterator data() const noexcept;
        bool empty() const noexcept;

        // Utility
        void swap(Blob& other) noexcept;
        void resize(size_type newSize);
        bool operator==(const Blob& other) const noexcept;

        // Default deleter function
        static void defaultDeleter(iterator data);
    };

} // namespace mce