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
      Dollar times(const int factor);
};
#endif // _PROJECT_NAME_LIB_HPP_
