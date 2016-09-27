const int maxStack = 16;

class IStack {
public:
  IStack() : _top(0) {}
  void Push(char i);
  char Pop();
  char Top() const;
  int Count() const;

private:
  char _arr[maxStack];
  int _top;
};
