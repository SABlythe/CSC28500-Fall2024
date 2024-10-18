#include <iostream>
#include <string>
using namespace std; 

unsigned long long int fibo(int num)
{
  if (num<=1) return num; 

  unsigned long long prev2;
  unsigned long long prev1=0;
  unsigned long long answer=1;

  for(int i=2; i<=num; i++)
  {
     prev2=prev1;
     prev1=answer;
     answer=prev1+prev2;
  }

  return answer; 
}

int main(int argc, char *argv[])
{
  unsigned int n;

  n = stoi(argv[1]);

  cout << fibo(n) << endl;

  return 0;
}
