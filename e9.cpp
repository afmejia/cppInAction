#include <iostream>

using namespace std;

class LivingBeing {
public:
  LivingBeing() { cout << "Living being: "; }
};

class Human : public LivingBeing {
public:
  Human() { cout << "Human\n"; }
};

class Tomato : public LivingBeing {
public:
  Tomato() { cout << "Tomato\n"; }
};

class Elephant : public LivingBeing {
public:
  Elephant() { cout << "Elephant\n"; }
};

int main(int argc, char const *argv[]) {
  Human h;
  Elephant e;
  Tomato t;
  return 0;
}
