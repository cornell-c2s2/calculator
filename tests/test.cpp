#include "adder.hpp"
#include <assert.h>
#include "Calculator.cpp"

void test_add() {
  int c = add_two_numbers(1, 2);
  assert(c == 3);
}

int main() {
  test_add();

  int res = add(0, 0);
  assert(res == 1); 
}