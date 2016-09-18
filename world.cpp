#include <iostream>

class World {
public:
  World(int i) { std::cout << "Hello from " << i << ".\n"; }

  ~World() { std::cout << "Good bye.\n"; }
};

World TheWorld(1);

int main() {
  World myWorld(2);
  std::cout << "Hello from main!\n";
}
