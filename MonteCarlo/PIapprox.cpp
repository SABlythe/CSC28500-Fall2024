#include <cstdlib>
#include <iostream>

using namespace std;

double getRandomDouble(double min, double max)
{
  double zeroToOne = ((double) rand()) / RAND_MAX;
  double scaled = zeroToOne * (max-min);
  double based = min + scaled;

  return based;
}

bool inCircle(double xPos, double yPos, double radius=1)
{
  if ( (xPos*xPos + yPos*yPos) <= radius*radius)
    return true;
  else
    return false; 
}

int main(int argc, char *argv[])
{
  if (argc!=2)
    {
      cerr << "USAGE: " << argv[0] << " <num-darts>" << endl;
      return 1;
    }

  unsigned long int nDarts, nHits;

  nDarts = stoi(argv[1]);
  nHits=0;

  // this part is optional, but probably a good idea
  //  seed the random number generator (change its starting value)
  srand(time(nullptr));
  
  for (unsigned long int i=0; i< nDarts; i++)
    {
      double x=getRandomDouble(0,1);
      double y=getRandomDouble(0,1);

      if (inCircle(x,y,1))
	nHits++;
    }

  double hitRatio = ((double)nHits)/nDarts;
  double piGuess = 4 * hitRatio;

  cout << "Approximation of pi: "<< piGuess << endl;
}
