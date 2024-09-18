#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  unsigned int number, pos;

  cout << "Enter number to pisk bit from: " ;
  cin >> number;

  cout << "What bit number do you want? ";
  cin >> pos;

  cout << "Number you gave is:"
       << std::bitset<32>(number) << endl;

  // build a mask to pick out bit we want.
  unsigned int mask =1;

  // left shift 1 bit into position we want,
  // leaving all others as 0's
  mask = mask << pos;

  cout << "Your mask will be: "
       << std::bitset<32>(mask) << endl;

  // calculate logical and of mask and number
  unsigned int logicalAnd = number & mask; 

  cout << "Your l-and will be:"
       << std::bitset<32>(logicalAnd) << endl;

  // "un"shift (i.e. right shift) anded result
  // to get bit value back ...
  unsigned int bitValue = logicalAnd >> pos;

  cout << "Your bit value:" << bitValue << endl;
  
  return 0;
}
