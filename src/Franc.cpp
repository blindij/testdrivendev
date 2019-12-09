// File: Franc.cpp
//
// Move Franc Class methods in own file
#include <TestDrivenDevbyExample/lib.hpp>

Franc::Franc(int value) : Money(value){}


bool Franc::equal(const Money &rhs) const {
   // we know the types are equal, so the cast won't throw
   auto r = dynamic_cast<const Franc&>(rhs);
   return (this->value == r.value);
}

int Franc::amount(){
      return value;
}

Franc Franc::operator*(int factor) const{
   Franc t = *this;
   t.value *= factor;
   return t;
}

Franc operator*(int factor, const Franc & d) {
   Franc t = d;
   t.value *= factor;
   return t;
}

Money* Franc::times(int multiplier){
   return new Franc(amount() * multiplier);
}
