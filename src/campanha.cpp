#include "campanha.hpp"

bool verify_args(int argc, char **argv) 
{
   if (argc == 2)
      return true;
   else 
      cout << "ERROR:   Missing arguments." << endl;
   return false;
}
