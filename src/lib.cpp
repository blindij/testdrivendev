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

Money* Money::Create(CurrencyType type, int amount){
   if (type == CT_Dollar) return new Dollar(amount);
   else if (type == CT_Franc) return new Franc(amount);
   else return NULL;
}

Money* Money::dollar(int amount){
   return dynamic_cast<Dollar *>(Money::Create(CT_Dollar, amount));
}

Money* Money::franc(int amount) {
   return dynamic_cast<Franc *>(Money::Create(CT_Franc, amount));
}

// ------------------------------------------------
// Class Dollar
// ------------------------------------------------
Dollar::Dollar(int value) : Money(value){ Money::Currency = "USD";}

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

Money* Dollar::times(int multiplier){
   return new Dollar(amount()*multiplier);
}

std::string Dollar::currency() const {
   return Currency;
}
