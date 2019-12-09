#ifndef _PROJECT_NAME_LIB_HPP_
#define _PROJECT_NAME_LIB_HPP_

#include <iostream>
#include <typeinfo>

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
   enum CurrencyType {CT_Dollar, CT_Franc};
   friend bool operator==(const Money &lhs, const Money &rhs);
   private:
      std::string Currency;

   protected:
      int value;
      virtual bool equal(const Money &) const;
      static Money* Create(CurrencyType type, int amount);
   public:
      Money(int val, std::string ct) : value(val), Currency(ct) {};
      static Money* dollar(int amount);
      static Money* franc(int amount);
      virtual Money* times(int multiplier) = 0;
      std::string currency() { return Currency; }
};

// ----------------------------------------------------
// Class dollar; for satisfying the multiply test from 
// Test Driven Development by Example
// ----------------------------------------------------
class Dollar : public Money {
   protected:
      virtual bool equal(const Money &) const;
   public:
      Dollar(int val, std::string currency);
      int amount();
      Dollar operator*(int factor) const;
      friend Dollar operator*(int factor, const Dollar& d);
      virtual Money* times(int multiplier) final;
};

// ----------------------------------------------------
// Class Franc - currently a copy of Dollar
// ----------------------------------------------------
class Franc : public Money {
   protected:
      virtual bool equal(const Money &) const;
   public:
      Franc(int val, std::string currency);
      int amount();
      Franc operator*(int factor) const;
      virtual Money* times(int multiplier) final;
      friend Franc operator*(int factor, const Franc & d);
};
#endif // _PROJECT_NAME_LIB_HPP_
