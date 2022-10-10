#include "campanha.hpp"

using namespace std;

int main(int argc, char **argv)
{
  //making a correct file opening
  if (!verify_args(argc, argv))
    return 0;
  string filename = argv[1];
  ifstream inputfile(filename);
  if (!inputfile.is_open()) 
  {
    cout <<  "ERROR:  file not found" << endl;
    return 0;
  }

  //starts the program
  while (true)
  { 
    //store and check the values of S and P
    string firstline;
    inputfile >> firstline;
    int S = stoi(firstline);
    inputfile >> firstline;
    int P = stoi(firstline);

    //check if values are correct and closing the program in case it´s done
    if (!verify_SP(S, P))
    {
      inputfile.close();
      break;
    }

    //stores the votes of the followers in a 2D vector
    int vec[S][4];
    int vote;
    string aux;

    for (int i = 0; i < S; i++)
    {
       for (int j = 0; j < 4; j++)
       {
          inputfile >> aux;
          vote = stoi(aux);
          if (vote > P)
          {
            cout << "ERROR: invalid inputs" << endl;
            return 0;
          }
          vec[i][j] = vote;
       }
    }
    
    //generates the outputs
    if(check_satisfability(S, P, vec[0]))
      cout << "sim" << endl;
    else
      cout << "nao" << endl;

  }

  return 0;
}