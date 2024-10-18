#include <cmath>
#include <iostream>
using namespace std; 

unsigned long long int fibo(int num)
{
  double fib = (1/sqrt(5)) * (pow( (1+sqrt(5))/2, num) - pow( (1-sqrt(5))/2, num));

  return (long long int) fib;
}

int main(int argc, char *argv[])
{
  unsigned int n;

  n = stoi(argv[1]);

  cout << fibo(n) << endl;

  return 0;
}
