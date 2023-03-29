#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "arrayd/arrayd.hpp"

TEST_CASE("first test"){
    auto Arr = ArrayD();
    SUBCASE("default") {
        CHECK(Arr.ssize() == 0);
    }


}