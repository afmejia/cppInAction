#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  Calculator theCalculator;
  bool status;
  do {
    // Prompt for input
    cout << "> ";
    Input input;
    status = theCalculator.execute(input);
    if(status)
      for(StackSeq seq(theCalculator.getStack()); !seq.atEnd(); seq.Advance())
        cout << "  " << seq.getNum() << endl;
  } while(status);
  return 0;
}
