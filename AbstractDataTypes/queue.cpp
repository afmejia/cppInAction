#include "queue.h"
#include <cassert>
#include <iostream>

using namespace std;

Queue::Queue() : _putIndex(0), _getIndex(0) {}

void Queue::Put(double i) {
  assert(_putIndex < maxQueue);
  _arr[_putIndex] = i;
  ++_putIndex;
}

double Queue::Get() {
  assert(_getIndex < _putIndex);
  return _arr[_getIndex++];
}

int main(int argc, char const *argv[]) {
  Queue q;
  q.Put(1);
  q.Put(2);
  q.Put(3);
  q.Put(4);
  cout << q.Get() << endl;
  cout << q.Get() << endl;
  cout << q.Get() << endl;
  cout << q.Get() << endl;
  return 0;
}
