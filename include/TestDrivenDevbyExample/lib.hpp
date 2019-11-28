#ifndef _PROJECT_NAME_LIB_HPP_
#define _PROJECT_NAME_LIB_HPP_

#include <iostream>

/// A dummy class for doing addition
/** A longer description that is redundant here because it's a simple class */
class AddTwo {
public:
  /// A static method for doing addition.
  /**
    \param a an integer
    \param b another integer
    \return the sum a+b
    */
  static int Add(int a, int b);
};
// ----------------------------------------------------
// Class Money - a super class for currency
// ----------------------------------------------------
class Money {
   protected:
      int value;
   public:
      Money(int val) : value(val) {};
      bool operator==(const Money & objd) const;
};

// ----------------------------------------------------
// Class dollar; for satisfying the multiply test from 
// Test Driven Development by Example
// ----------------------------------------------------
class Dollar : public Money {
   public:
       Dollar(int val);
      int amount();
      Dollar operator*(int factor) const;
      friend Dollar operator*(int factor, const Dollar& d);
};

// ----------------------------------------------------
// Class Franc - currently a copy of Dollar
// ----------------------------------------------------
class Franc : public Money {
   public:
      Franc(int val);
      int amount();
      Franc operator*(int factor) const;
//      bool operator==(const Franc & objd) const;
      friend Franc operator*(int factor, const Franc & d);
};
#endif // _PROJECT_NAME_LIB_HPP_
