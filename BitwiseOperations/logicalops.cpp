#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
  unsigned int val1, val2;

  cout << "Please enter two values: ";
  cin >> val1 >> val2;

  cout << "Logical and of " << val1 << " && " << val2 << " gives:"
       << (val1 && val2) << endl;

  cout << "Bitwise and of " << val1 << " & " << val2 << " gives:"
       << (val1 & val2) << endl;

  cout << "Logical or of " << val1 << " || " << val2 << " gives:"
       << (val1 || val2) << endl;

  cout << "Bitwise or of " << val1 << " | " << val2 << " gives:"
       << (val1 | val2) << endl;

  cout << "Bitwise xor of " << val1 << " ^ " << val2 << " gives:"
       << (val1 ^ val2) << endl;

  cout << "Bitwise negation of  ~" << val1 << " gives:"
       << ~val1 << endl;

  unsigned int mask =1;
  mask << 2; // note:compiler should warn you about this!
  cout << "magic:" << (val1 & mask) << endl;

  return 0;
}
