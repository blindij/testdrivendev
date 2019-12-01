#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <TestDrivenDevbyExample/lib.hpp>

// --------------------------------------------
//  strategies for getting from red to green
//  (Kent Beck)
//  1. Fake it. Return a constant and gradually replace constants with
//  variables until you have the real code.
//  2. Use Obvious Implementation - Type in the real implementation
//  3. Triagulation
//  

TEST_CASE("TDDbyexample test") {
  SECTION("Addition") {
    REQUIRE(AddTwo::Add(1, 9) == 10);
    REQUIRE(AddTwo::Add(-9, 9) == 0);
  }
}

TEST_CASE("Test multiplication","[dollar],[multiplication]"){
   Dollar five = {5};
   REQUIRE( (five * 2) == (*(new Dollar{10})) );
   SECTION("Mulitply by three","[3x]"){
      REQUIRE( (five * 3) == (*(new Dollar{15})) );
      REQUIRE( (3 * five) == (*(new Dollar{15})) );
   }
}

TEST_CASE("Value Object implement equals","[equals]"){
   REQUIRE( *(new Dollar{5}) == *(new Dollar{5}) );
   REQUIRE( !( *(new Dollar{5}) == *(new Dollar{6})) );
   REQUIRE( *(new Franc{5}) == *(new Franc{5}) );
   REQUIRE( !(*(new Dollar{5}) == *(new Franc{5})) );
}

TEST_CASE("Test franc multiplication","[franc],[multiplication]"){
   Franc five = {5};
   REQUIRE( (five * 2) == (*(new Franc{10})) );
   SECTION("Mulitply by three","[3x]"){
      REQUIRE( (five * 3) == (*(new Franc{15})) );
      REQUIRE( (3 * five) == (*(new Franc{15})) );
   }
}
