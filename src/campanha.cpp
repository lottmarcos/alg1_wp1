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
   graph g(2*P +1);

   int x1, x2, y1, y2;
   for (int i = 0; i < S; i++)
   {  
      x1 = *(vec + i*4 + 0);
      x2 = *(vec + i*4 + 1);
      y1 = *(vec + i*4 + 2);
      y2 = *(vec + i*4 + 3);
      
      if (x1 == 0) 
         g.add_edge(x2, (x2 + P));
      else if (x1 == 0)
         g.add_edge(x1, (x1 + P));
      else 
      {
         g.add_edge((x1 + P), x2);
         g.add_edge((x2 + P), x1);
      }

      if (y1 == 0)
         g.add_edge(y2, (y2 + P));
      else if (y2 == 0)
         g.add_edge(y1, (y1 + P));
      else
      {
         g.add_edge(y1, (y2 + P));
         g.add_edge(y2, (y1 + P));
      }
   }

   g.CFC(P); //check if there is a CFC in the graph

   return g.valid;
}
int count_numbers(string str) {
    stringstream s(str);
    string n;
 
    int count = 0;
    while (s >> n)
        count++;
    return count;
}
bool is_valid(string cfc, int P)
{
   stringstream ss(cfc);
   int n = count_numbers(cfc);
   if (n == 1)
      return true;

   int array[n];
   int count = 0;
   string aux;
   while (ss >> aux) {
      array[count] = stoi(aux);
      count++;
   }
   
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if ((array[i] == array[j] + P) || (array[i] == array[j] - P))
            return false;
      }
   }
   
   return true;
}

//class graph
graph::graph(int v)
{
    this->v = v;
    this->valid = true;
    adj = new list<int>[v];
}
void graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}
void graph::CFC_aux(int u, int disc[], int low[],
                   stack<int> *st, bool stackMember[], int P)
{
   string cfc;
   static int time = 0;
   //initialize discovery time and low value
   disc[u] = low[u] = ++time;
   st->push(u);
   stackMember[u] = true;
 
   //go through all vertices adjacent to this
   list<int>::iterator i;
   for (i = adj[u].begin(); i != adj[u].end(); ++i)
   {
      int v = *i; //v is current adjacent of 'u'

      //if v is not visited yet, then recur for it
      if (disc[v] == -1)
      {
         CFC_aux(v, disc, low, st, stackMember, P);
 
         //check if the subtree rooted with 'v' has a connection to one of the ancestors of 'u'
         low[u] = min(low[u], low[v]);
      }
 
      //update low value of 'u' only of 'v' is still in stack (i.e. it's a back edge, not cross edge).
      else if (stackMember[v] == true)
         low[u] = min(low[u], disc[v]);
    }
 
   //head node found, pop the stack and print an CFC
   int w = 0; //to store stack extracted vertices
   if (low[u] == disc[u])
   {
      while (st->top() != u)
      {
          w = (int) st->top();
          cfc += to_string(w);
          cfc += " ";
          stackMember[w] = false;
          st->pop();
      }
      w = (int) st->top();
      cfc += to_string(w);

      if (!is_valid(cfc, P)) //check if the cfc is fatal or not
         valid = false;
      cfc = "";
      stackMember[w] = false;
      st->pop();
   }
}
void graph::CFC(int P)
{
   int *disc = new int[v];
   int *low = new int[v];
   bool *stackMember = new bool[v];
   stack<int> *st = new stack<int>();
 
   //initialize disc and low, and stackMember arrays
   for (int i = 0; i < v; i++)
   {
       disc[i] = -1;
       low[i] = -1;
       stackMember[i] = false;
   }
 
   //call the recursive helper function to find CFCs in DFS tree with vertex 'i'
   for (int i = 0; i < v; i++)
       if (disc[i] == -1)
           CFC_aux(i, disc, low, st, stackMember, P);
}