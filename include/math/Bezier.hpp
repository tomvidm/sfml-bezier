#pragma once

#include <array>
#include <math.h>

#include "Binomial.hpp"

namespace math {
    template <typename T>
    T deCasteljau(std::vector<T> points, const float t) {
        const size_t n = points.size();
        while (points.size() > 2) {
            for (size_t i = 0; i < n - 1; i++) {
                points[i] = points[i] * (1 - t) + points[i + 1] * t;
            }
            points.pop_back();
        }
        return points[0] * (1 - t) + points[1] * t;
    }
} // namespace math