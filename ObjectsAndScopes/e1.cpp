#include <iostream>

using namespace std;

class World {
public:
  World(int id) : _id(id) { cout << "Hello from " << _id << endl; }

  ~World() { cout << "Good bye from " << _id << endl; }

private:
  int const _id;
};

int main() {
  for (int i = 1; i <= 2; i++)
    World a(i);
}
