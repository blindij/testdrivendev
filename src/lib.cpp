#include <TestDrivenDevbyExample/lib.hpp>

// -----------------------------------------------------
// The dummy class which came with the cookierecipe
// -----------------------------------------------------
int AddTwo::Add(int a, int b) { return a + b; }

// -----------------------------------------------------
// The money class 
// -----------------------------------------------------
bool operator==(const Money &lhs, const Money &rhs) {
   return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Money::equal(const Money &rhs) const {
   return false;   // Comparing money to money meaningless
}

Dollar::Dollar(int value) : Money(value){}

bool Dollar::equal(const Money &rhs) const {
   // we know the types are equal, so the cast won't throw
   auto r = dynamic_cast<const Dollar&>(rhs);
   return (this->value == r.value);
}

int Dollar::amount(){
      return value;
}

Dollar Dollar::operator*(int factor) const{
   Dollar t = *this;
   t.value *= factor;
   return t;
}

Dollar operator*(int factor, const Dollar & d) {
   Dollar t = d;
   t.value *= factor;
   return t;
}

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

