#include <iostream>
#include <vector>

using namespace std;

/*class Average {
public:
  Average() {}

  void addValue(int value) { _values.push_back(value); }

  double getAverage() {
    for (int i = 0; i <= _values.size(); i++)
      _av += _values[i];
    _av = _av / _values.size();
    return _av;
  }

private:
  vector<double> _values;
  double _av;
};*/

class Average {
public:
  Average() : _sum(0), _count(0) {}
  void Put(double n) {
    _sum = _sum + n;
    ++_count;
  }
  double Get() const { return _sum / _count; }

private:
  double _sum;
  int _count;
};

int main(int argc, char const *argv[]) {
  Average av;
  av.Put(5);
  av.Put(5);
  av.Put(5);
  cout << "Average = " << av.Get();
  return 0;
}
