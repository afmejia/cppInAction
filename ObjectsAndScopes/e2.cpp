#include <iostream>

using namespace std;

class Hand {
public:
  Hand(int finger) : _nfingers(finger) {}

private:
  int const _nfingers;
};

class Glove {
public:
  Glove(int cFingers) : _n(cFingers), _hand(_n) {
    cout << "Glove with " << _n << " fingers\n";
  }

private:
  Hand _hand;
  int _n;
};

int main(int argc, char const *argv[]) {
  Glove glove(4);
  return 0;
}
