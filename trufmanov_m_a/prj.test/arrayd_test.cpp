#define DOCTEST_CONFIG_IMPLEMENTS_WITH_MAIN
#include <doctest/doctest.h>
#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayd] - arrayd ctor") {
	SUBCASE("throws"){
		CHECK_THROWS(Arrayd(-1));
		
	
	}



}