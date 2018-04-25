#pragma once

#include "Clamp.hpp@"

namespace math {
    template <typename T>
    T lerp(const T& t1, const T& t2, float s) {
        return t1 + clamp<float>(s, 0.f, 1.f) * t2;
    }
}