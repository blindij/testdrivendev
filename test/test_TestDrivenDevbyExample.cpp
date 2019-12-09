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

TEST_CASE("Abstract method times()","[dollar],[times]"){
   Money *pfive = Money::dollar(5);
   REQUIRE( ((*pfive->times(2))) == (*(new Dollar{10})));
}

//TEST_CASE("Test multiplication","[!hide],[dollar]"){
//   Money* pfive = Money::dollar(5);
//   REQUIRE( ((*pfive) * 2) == (*(new Dollar{10})) );
//   SECTION("Mulitply by three","[3x]"){
//      REQUIRE( ((*pfive) * 3) == (*(new Dollar{15})) );
//      REQUIRE( (3 * (*pfive)) == (*(new Dollar{15})) );
//   }
//}
//

TEST_CASE("Value Object implement equals","[equals]"){
   REQUIRE( *Money::dollar(5) == *Money::dollar(5) );
   REQUIRE( !( *Money::dollar(5) == *Money::dollar(6)) );
   REQUIRE( *(new Franc{5}) == *(new Franc{5}) );
   REQUIRE( !(*Money::dollar(5) == *(new Franc{5})) );
}

TEST_CASE("Test franc multiplication","[franc],[times]"){
   Money *pfive = Money::franc(5);
   REQUIRE( (*pfive->times(2)) == (*Money::franc(10)) );
   REQUIRE( *pfive->times(3) == *Money::franc(15) );
}
