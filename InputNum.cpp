#include <iostream>

class InputNum {
public:
  InputNum() {
    std::cout << "Enter number ";
    std::cin >> _num;
  }

  int GetValue() const { return _num; }

private:
  int _num;
};

int main() {
  InputNum num;
  std::cout << "The value is " << num.GetValue() << "\n";
  return 0;
}
