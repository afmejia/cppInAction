#include <iostream>

using namespace std;

class VerBar {
public:
  VerBar(int n) : _n(n) {
    for (int i = 1; i <= _n; i++)
      cout << "|" << endl;
  }

private:
  int _n;
};

class HorBar {
public:
  HorBar(int n) : _n(n) {
    cout << "+";
    for (int i = 1; i <= _n; i++)
      cout << "-";
    cout << "+" << endl;
  }

private:
  int _n;
};

class Frame {
public:
  Frame(int hor, int ver) : _up(hor), _down(hor), _mid(ver) {}

private:
  HorBar _up;
  VerBar _mid;
  HorBar _down;
};

int main() {
  Frame frame(10, 2);
  return 0;
}
