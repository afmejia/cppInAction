#include <cassert>
#include <iostream>

using namespace std;

const int maxStack = 16;

class IStack {
  friend class StackSeq;  // give it access to private members
 public:
  IStack() : _top(0) {}
  void push(int i);
  int pop();

 private:
  int _arr[maxStack];
  int _top;
};

class StackSeq {
 public:
  StackSeq(IStack const &stack);
  bool atEnd() const;  // are we done yet?
  void advance();      // move to next item
  int getNum() const;  // retrieve current item
 private:
  IStack const &_stack;  // reference to stack
  int _iCur;             // current index into stack
};

void IStack::push(int i) {
  assert(_top < maxStack);
  _arr[_top] = i;
  ++_top;
}

StackSeq::StackSeq(IStack const &stack)
    : _iCur(0),
      _stack(stack)  // init reference
{}

bool StackSeq::atEnd() const {
  return _iCur == _stack._top;  // friend: can access _top
}

void StackSeq::advance() {
  assert(!atEnd());  // not at end
  ++_iCur;
}

int StackSeq::getNum() const {
  return _stack._arr[_iCur];  // friend: can access _arr
}

int main(int argc, char const *argv[]) {
  IStack theStack;
  theStack.push(1);
  theStack.push(2);
  theStack.push(3);

  for (StackSeq seq(theStack); !seq.atEnd(); seq.advance())
    cout << "  " << seq.getNum() << endl;
  return 0;
}