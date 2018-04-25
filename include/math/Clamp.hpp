#pragma once

namespace math {
    template <typename T>
    T clamp(const T val, const T min, const T max) {
        return val < min ? min : (val < max ? val : max);
    }
}