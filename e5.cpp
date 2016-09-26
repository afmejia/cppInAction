#include <iostream>

using namespace std;

class Factorial {
public:
  Factorial(int n) : _n(n), _fac(1) {

    for (int i = 1; i <= _n; i++)
      _fac *= i;
    cout << _fac << endl;
  }

private:
  int _n;
  int _fac;
};

int main(int argc, char const *argv[]) {
  Factorial f(5);
  return 0;
}
