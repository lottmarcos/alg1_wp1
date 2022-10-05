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
    if (!verify_SP(S, P))
    {
      inputfile.close();
      break;
    }
  }


  
  return 0;
}

