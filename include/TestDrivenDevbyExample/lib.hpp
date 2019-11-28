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
// Class dollar; for satisfying the multiply test from 
// Test Driven Development by Example
// ----------------------------------------------------
class Dollar {
   private:
      int value;
   public:
      Dollar(int val) : value(val) {};
      int amount();
      Dollar operator*(int factor) const;
      bool operator==(const Dollar & objd) const;
      friend Dollar operator*(int factor, const Dollar& d);
};

class Franc {
   private:
      int value;
   public:
      Franc(int val) : value(val) {};
      int amount();
      Franc operator*(int factor) const;
      bool operator==(const Franc & objd) const;
      friend Franc operator*(int factor, const Franc & d);
};
#endif // _PROJECT_NAME_LIB_HPP_
