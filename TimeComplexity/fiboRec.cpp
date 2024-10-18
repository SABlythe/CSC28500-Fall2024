#include <iostream>
using namespace std; 

unsigned long long int fibo(int num)
{
  if (num<=1) return num; 

  return fibo(num-1) + fibo(num-2);
}

int main(int argc, char *argv[])
{
  unsigned int n;

  n = stoi(argv[1]);

  cout << fibo(n) << endl;

  return 0;
}
