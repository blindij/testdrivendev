#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <TestDrivenDevbyExample/lib.hpp>

TEST_CASE("TDDbyexample test") {
  SECTION("Addition") {
    REQUIRE(AddTwo::Add(1, 9) == 10);
    REQUIRE(AddTwo::Add(-9, 9) == 0);
  }
}

TEST_CASE("Test multiplication","[multiplication]"){
   Dollar five = {5};
   five.times(2);
   REQUIRE(five.amount() == 10);
}
