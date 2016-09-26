#include <iostream>

using namespace std;

class CelestialBody {
public:
  CelestialBody(double mass) : _mass(mass) {
    cout << "Creating celestial body of mass " << _mass << "\n";
  }

  ~CelestialBody() {
    cout << "Destroying celestial body of mass " << _mass << "\n";
  }

private:
  const double _mass;
};

class Planet : public CelestialBody {
public:
  Planet(double mass, double albedo) : CelestialBody(mass), _albedo(albedo) {
    cout << "Creating a planet of albedo: " << _albedo << "\n";
  }

  ~Planet() { cout << "Destroying a planet with albedo " << _albedo << "\n"; }

private:
  const double _albedo;
};

int main(int argc, char const *argv[]) {
  Planet earth(5972e24, 0.30);
  return 0;
}
