#include "gtest/gtest.h"

#include "math/Bezier.hpp"
#include "math/Binomial.hpp"
#include "math/Clamp.hpp"
#include "math/LinearInterpolation.hpp"

TEST(MathTests, clamp_works_fine) {
    EXPECT_EQ(math::clamp<float>(0.5f, 0.f, 1.f), 0.5f);
    EXPECT_EQ(math::clamp<float>(1.5f, 0.f, 1.f), 1.f);
    EXPECT_EQ(math::clamp<float>(-0.5f, 0.f, 1.f), 0.f);
}

TEST(MathTests, lerp_works_fine) {
    // Check that lerp correctly interpolates
    EXPECT_EQ(math::lerp<float>(0.f, 100.f, 0.5f), 50.f);
    EXPECT_EQ(math::lerp<float>(0.f, 100.f, 0.f), 0.f);

    // Check that interpolation factor is properly clamped
    EXPECT_EQ(math::lerp<float>(0.f, 100.f, 1.5f), 100.f);
}

TEST(MathTests, binomial_coefficients_are_computed_correctly) {
    EXPECT_EQ(math::combinations<long unsigned>(4, 0), 1);
    EXPECT_EQ(math::combinations<long unsigned>(4, 1), 4);
    EXPECT_EQ(math::combinations<long unsigned>(4, 2), 6);
    EXPECT_EQ(math::combinations<long unsigned>(4, 3), 4);
    EXPECT_EQ(math::combinations<long unsigned>(4, 4), 1);
    EXPECT_EQ(math::combinations<long unsigned>(4, 4), 1);
    EXPECT_EQ(math::combinations<long unsigned>(24, 16), 735471);
    EXPECT_EQ(math::combinations<long unsigned>(24, 12), 2704156);
}

TEST(MathTests, bezier_weights_are_computed_correctly) {

}