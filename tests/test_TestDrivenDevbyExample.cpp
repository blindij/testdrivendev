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

TEST_CASE("Test multiplication","[multiplication]"){
   Dollar five = {5};
   Dollar product = five.times(2);
   REQUIRE( five.operator*(2).equals((*(new Dollar{10}))) );
   SECTION("Mulitply by three","[3x]"){
      product = five.times(3);
      REQUIRE( product.equals(*(new Dollar{15})) );
   }
}

TEST_CASE("Value Object implement equals","[equals]"){
   Dollar f={5};
   Dollar g={5};
   REQUIRE (  f.equals(g) );
   SECTION("Value Object implement equals. Here it is no","[equalsnot]"){
      Dollar h = {7};
      REQUIRE(  !f.equals(h) );

   }
}
