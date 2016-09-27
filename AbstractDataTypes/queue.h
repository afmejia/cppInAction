const int maxQueue = 16;

class Queue {
public:
  Queue();
  void Put(double i);
  double Get();

private:
  int _putIndex;
  int _getIndex;
  double _arr[maxQueue];
};
