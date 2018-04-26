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

    template <typename T>
    T bezier(const std::vector<T>& controlPoints, const float t) {
        const unsigned n = controlPoints.size();
        if (n == 3) {
            const float mt = 1 - t;
            const float mtmt = mt * mt;
            return controlPoints[0] * mtmt +
                   controlPoints[1] * 2.f * mt * t +
                   controlPoints[2] * t * t;
        } // special case: quadratic
        else if (n == 4) {
            const float t2 = t * t;
            const float t3 = t2 * t;
            const float mt = 1 - t;
            const float mt2 = mt * mt;
            const float mt3 = mt2 * mt;
            return controlPoints[0] * mt3 +
                   controlPoints[1] * 3.f * mt2 * t +
                   controlPoints[2] * 3.f * mt * t2 +
                   controlPoints[3] * t3;
        } // special case: cubic 
        else {
            T newPoint;
            for (unsigned i = 0; i < n; i++) {
                const float bin = math::combinations(n - 1, i);
                const float fnmi = static_cast<float>(n - i - 1);
                const float fi = static_cast<float>(i);
                newPoint += controlPoints[i] * bin * powf(1 - t, fnmi) * powf(t, fi);
            }
            return newPoint;
        } // general case
    }
} // namespace math