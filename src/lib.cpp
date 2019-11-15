#include <TestDrivenDevbyExample/lib.hpp>

int AddTwo::Add(int a, int b) { return a + b; }

int Dollar::amount(){
      return value;
}

void Dollar::times(const int factor){
   value *= factor;
}
