#include "campanha.hpp"

//global functions
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
   if ((S < 0 || S > 1000) && (P < 0 || P > 10000))
   {
      cout << "ERROR:   Wrong numbers set for S or P." << endl;
      return false;
   }
   else if (S == 0 && P == 0)
   {
      return false;
   }
   return true;
}
bool check_satisfability(int S, int P, int *vec)
{
   for (int i = 0; i < S; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         cout << *(vec + i*4 + j) << " ";
      }
      cout << endl;
      
   }
   return true;
   
}

//class graph
void graph::addvertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        vertex *v;
        v = new vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}
void graph::addedge(const string& from, const string& to, double cost)
{
    vertex *f = (work.find(from)->second);
    vertex *t = (work.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}