#include "adder.h"
#include <assert.h>

void test_add() {
  int c = add_two_numbers(1, 2);
  assert(c == 3);
}

int main() {
  test_add();
}