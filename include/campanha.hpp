#include <iostream>
#include<bits/stdc++.h>
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
int count_numbers(string str);
bool is_valid(string cfc, int P);

//graph class
class graph
{
public:
   int v;     //n° of vertices
   bool valid;    
   list<int> *adj;    //pointer to an array containing adjacency lists
   void CFC_aux (int u, int disc[], int low[],
                stack<int> *st, bool stack_member[], int P);
    graph(int v);
    void add_edge(int v, int w);
    void CFC(int P);
};