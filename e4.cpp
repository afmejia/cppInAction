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

class Ladder {
public:
  Ladder(int hor, int ver)
      : _ver(ver), _hor(hor), _up(_hor, _ver), _mid(_ver), _down(_hor, _ver) {}

private:
  int _hor;
  int _ver;
  Frame _up;
  VerBar _mid;
  Frame _down;
};

int main(int argc, char const *argv[]) {
  Ladder lad(5, 2);
  return 0;
}
