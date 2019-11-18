#include <TestDrivenDevbyExample/lib.hpp>

int AddTwo::Add(int a, int b) { return a + b; }

int Dollar::amount(){
      return value;
}

Dollar Dollar::times(const int factor){
   Dollar t = *this;
   t.value *= factor;
   return t;
}

bool Dollar::equals(const Dollar& dobj){
   return this->value == dobj.value;
}
