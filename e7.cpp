#include <iostream>

using namespace std;

class Two {
public:
  Two() { cout << "Program "; }

  ~Two() { cout << "Program "; }
};

class Three {
public:
  Three() { cout << "makes "; }

  ~Three() { cout << "makes "; }
};

class Four {
public:
  Four() { cout << "objects "; }

  ~Four() { cout << "objects "; }
};

class Five {
public:
  Five() { cout << "with "; }

  ~Five() { cout << "with "; }
};

class One : public Two {
public:
  One() { cout << "class "; }

  ~One() { cout << "class "; }

private:
  Three _three;
  Four _four;
  Five _five;
};

int main(int argc, char const *argv[]) {
  One one;
  cout << "\n";
  return 0;
}
