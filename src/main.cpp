#include "campanha.hpp"

using namespace std;

int main(int argc, char **argv)
{
  if (!verify_args(argc, argv))
    return 0;
  char *input = argv[1];

  cout << input << endl;

  
  return 0;
}

