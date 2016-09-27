#include "stack.h"
#include <cassert>
#include <iostream>

using namespace std;

// compile with NDEBUG = 1 to get rid of assertions

void IStack::Push(char i) {
  assert(_top < maxStack);
  _arr[_top] = i;
  ++_top;
}

char IStack::Pop() {
  assert(_top > 0);
  --_top;
  return _arr[_top];
}

char IStack::Top() const {
  assert(_top > 0);
  return _arr[_top];
}

int IStack::Count() const { return _top; }

int main(int argc, char const *argv[]) {
  IStack stack;
  stack.Push('h');
  stack.Push('e');
  stack.Push('l');
  stack.Push('l');
  stack.Push('o');
  cout << stack.Pop();
  cout << stack.Pop();
  cout << stack.Pop();
  cout << stack.Pop();
  cout << stack.Pop();
  cout << "\n";
  return 0;
}
