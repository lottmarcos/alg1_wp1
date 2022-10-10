#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

//global functions
bool verify_args(int argc, char **argv);
bool verify_SP(int S, int P);
bool check_satisfability(int S, int P, int *vec);

//graph class
struct vertex {
    typedef pair<int, vertex*> ve;
    vector<ve> adj; //cost of edge, destination vertex
    string name;
    vertex(string s) : name(s) {}
};
class graph
{
public:
    typedef map<string, vertex *> vmap;
    vmap work;
    void addvertex(const string&);
    void addedge(const string& from, const string& to, double cost);
};
