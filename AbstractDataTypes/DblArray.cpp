#include <cassert>
#include <iostream>

const int maxCells = 16;

using namespace std;

class DblArray {
public:
  DblArray();
  void Set(int i, double val);
  double Get(int i) const;
  bool IsSet(int i) const;

private:
  double _arr[maxCells];
  bool _setValues[maxCells];
};

DblArray::DblArray() {
  for (int i = 0; i < maxCells; i++)
    _setValues[0] = false;
}

bool DblArray::IsSet(int i) const {
  assert(i < maxCells);
  return _setValues[i];
}

void DblArray::Set(int i, double val) {
  assert(i < maxCells);
  if (!IsSet(i)) {
    _arr[i] = val;
    _setValues[i] = true;
  }
}

double DblArray::Get(int i) const {
  assert(i < maxCells && IsSet(i));
  return _arr[i];
}

int main(int argc, char const *argv[]) {
  DblArray arr;
  arr.Set(2, 4.0);
  arr.Set(4, 5.9);
  cout << arr.Get(4) << endl;
  return 0;
}
