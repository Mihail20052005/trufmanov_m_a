#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "arrayd/arrayd.hpp"

TEST_CASE("resize") {
    auto arr = ArrayD();
    SUBCASE("default") {
        CHECK(arr.ssize() == 0);
    }
}