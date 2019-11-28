#include <TestDrivenDevbyExample/lib.hpp>

int AddTwo::Add(int a, int b) { return a + b; }

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

bool Dollar::operator==(const Dollar & dobj) const {
   return this->value == dobj.value;
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

bool Franc::operator==(const Franc & dobj) const {
   return this->value == dobj.value;
}
