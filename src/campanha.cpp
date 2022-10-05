#include "campanha.hpp"

bool verify_args(int argc, char **argv)
{
   if (argc == 2)
   {
      return true;
   }
   else 
   {
      cout << "ERROR:   Missing arguments." << endl;
      return false;
   }
}

bool verify_SP(int S, int P)
{
   if ((S < 0 || S > 1000) && P < 0 || P > 10000)
   {
      cout << "ERROR:   Wrong numbers set for S or P." << endl;
      return false;
   }
   else if (S == 0 && P == 0)
   {
      return false;
   }

}