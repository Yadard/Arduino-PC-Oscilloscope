#ifndef ARRAY_H
#define ARRAY_H

#include <Arduino.h>

namespace AUL {
namespace Containers {

template <typename T, size_t SIZE>
class Array {
  public:
    struct Iterator {
        using value_type = T;
        using pointer = T *;
        using reference = T &;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        // Prefix increment
        Iterator &operator++() {
            m_ptr++;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };

      private:
        pointer m_ptr;
    };

    Array() {}
    Array(T initVal) { fillPush(initVal); }

    T const *get(size_t index) {
        if (index >= used)
            return nullptr;

        return buffer + index;
    }
    T const *getFirst() {
        if (empty())
            return nullptr;

        return buffer;
    }
    T const *getLast() {
        if (empty())
            return nullptr;

        return buffer + used - 1;
    }

    /*
     * You can only set indices that you're using already.
     * To set any position you will need to fill the array.
     */
    void setPush(size_t index, T value) {
        if (index < size())
            buffer[index] = value;
    }

    /*
     * You can only set indices that you're using already.
     * To set any position you will need to fill the array.
     */
    template <class... Args>
    void setEmplace(size_t index, Args... args) {
        if (index < size())
            buffer[index] = T(args...);
    }

    void startPush(T value) {
        if (size() < capacity()) {
            for (int i = size(); i >= 0; i--) {
                if (i == 0)
                    buffer[i] = value;
                else
                    buffer[i] = buffer[i - 1];
            }
            ++used;
        }
    }
    template <class... Args>
    void startEmplace(Args... args) {
        if (size() < capacity()) {
            for (int i = size(); i >= 0; i--) {
                if (i == 0)
                    buffer[i] = T(args...);
                else
                    buffer[i] = buffer[i - 1];
            }
            ++used;
        }
    }

    void endPush(T value) {
        if (size() < capacity())
            buffer[used++] = value;
    }
    template <class... Args>
    void endEmplace(Args... args) {
        if (size() < capacity())
            buffer[used++] = T(args...);
    }

    inline size_t size() { return used; }
    inline size_t capacity() { return SIZE; }
    bool empty() { return size() == 0; }

    Iterator begin() { return Iterator(buffer); }
    Iterator end() { return Iterator(&buffer[used]); }

    void fillPush(T value) {
        for (size_t i = 0; i < capacity(); i++)
            buffer[i] = value;
        used = capacity();
    }
    template <class... Args>
    void fillEmplace(Args... args) {
        for (size_t i = 0; i < capacity(); i++)
            buffer[i] = T(args...);
        used = capacity();
    }

    void clear() { used = 0; }

  private:
    T buffer[SIZE];
    size_t used = 0;
};

} // namespace Containers

} // namespace AUL

#endif // ARRAY_H