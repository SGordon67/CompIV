// Scott Gordon

#ifndef Body_INCLUDE
#define Body_INCLUDE
#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class ED{
    private:
    string aString;
    string bString;
    vector< vector<int> > vec;
    
    public:
    ED(string a, string b);
    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int OptDistance();
    string Alignment();
};

#endif