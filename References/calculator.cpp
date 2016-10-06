#include <iostream>
#include <cassert>

using namespace std;

using namespace std;

const int maxStack = 16;

class IStack {
  friend class StackSeq;  // give it access to private members
 public:
  IStack() : _top(0) {}
  void push(int i);
  bool IsFull() const();
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

class Input {
public:
  Input(){cout << "Input created\n"; }
  int token const();
}

class Calculator {
public:
  Calculator() : _done(false) {}
  bool execute (Input const &input);
  IStack const &getStack() const;

private:
  IStack _stack;
  bool _done;

  int calculate(int num1, int num2, int token) const;
};

bool Calculator::execute (Input const &input) {
  int token = input.token();
  bool status = false;  // assume failure

  if (token == tokError)
    cout << "Unknown token\n";
  else if (token == tokNumber)
    if (_stack.IsFull())
      cout << "Stack is full\n";
    else {
      _stack.push(input.number());
      status = true; //succes
    }
  else {
    assert(token == '+' || token == '-' || token == '*' || token == '/');
    if (_stack.isEmpty())
      cout << "Stack is empty\n";
    else {
      int num2 = _stack.pop();
      int num1;

      //Special case, when only one number on the stack: use this number for both operands.
      if (_stack.isEmpty())
        num1 = num2;
      else
        num1 = _stack.pop();

      _stack.push(calculate(num1, num2, token))
      status = true;
    }
  }
  return status;
}

IStack const &Calculator::getStack() const {
  return _stack;
}

int Calculator::calculate(int num1, int num2, int token) const {
  int result;

  if (token == '+')
    result = num1 + num2;
  else if (token == '-')
    result = num1 - num2;
  else if (token == '*')
    result = num1 * num2;
  else if (token == '/') {
    if (num2 == 0) {
      cout << "Division by zero\n";
      result = 0;
    }
    else
      result = num1 / num2;
  }

  return result;
}

int main(int argc, char const *argv[]) {
  Calculator theCalculator;
  bool status;
  do {
    // Prompt for input
    cout << "> ";
    Input input;
    status = theCalculator.execute(input);
    if(status)
      for(StackSeq seq(theCalculator.getStack()); !seq.atEnd(); seq.Advance())
        cout << "  " << seq.getNum() << endl;
  } while(status);
  return 0;
}
