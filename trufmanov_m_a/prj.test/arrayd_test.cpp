#define DOCTEST_CONFIG_IMPLEMENTS_WITH_MAIN
#include <doctest/doctest.h>
#include "arrayd/arrayd.hpp"

TEST_CASE("[arrayd] - arrayd ctor") {
	SUBCASE("v"){
		auto arr = ArrayD();
		CHECK(arr.ssize() == 0);
	}



}