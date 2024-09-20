#include <bitset>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  unsigned int number, pos;

  cout << "Enter number to set bit within: " ;
  cin >> number;

  /*
  cout << "What bit number do you want? ";
  cin >> pos;
  */
  cout << "Number you gave is:"
       << std::bitset<32>(number) << endl;

  /*
  // build a mask to set bit we want.
  unsigned int mask =1;

  // left shift 1 bit into position we want,
  // leaving all others as 0's
  mask = mask << pos;

  cout << "Your mask will be: "
       << std::bitset<32>(mask) << endl;

  // calculate logical or of mask and number
  unsigned int logicalXor = number ^ mask; 

  cout << "Your l-xor will be:"
       << std::bitset<32>(logicalXor) << endl;
  */
  
  number = ~number;
  cout << "Number is now :    "
       << std::bitset<32>(number) << endl;
  
  return 0;
}
