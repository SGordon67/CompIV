#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "ED.hpp"
using namespace std;

// constructor definition
ED::ED(string a, string b){
    aString = a;
    bString = b;
    // resize the vector
    // fill the last row and last column with
    // values used to calculate the actual values of the 2d vector
    vec.resize(a.length()+1);
    for(unsigned int i = 0; i < a.length()+1; i++){
        vec[i].resize(b.length()+1);
        for(unsigned int j = 0; j < b.length()+1; j++){
            if(j == b.length()){
                vec[i][j] = ((a.length() * 2)-(i*2));
            }
            if(i == a.length()){
                vec[i][j] = ((b.length() * 2)-(j*2));
            }
        }
    }
};

// tells the penalty given 2 chars
int ED::penalty(char a, char b){
    auto ret = [](char a, char b){
    if(a == b){return 0;}
        else return 1;
    };
    return ret(a,b);
}

// simple method returns the min of 3 values
int ED::min(int a, int b, int c){
    if (a <= b && a <= c) {
        return a;
    } else if (b <= c && b <= a) {
        return b;
    } else {
        return c;
    }
}

// opt distance algorithm outlined.
//***************************************************************//
int ED::OptDistance(){
    int vert, hori, diag = 0;

    for(int i = (this->aString.length()-1); i >= 0; i--){
        for(int j = (this->bString.length()-1); j >= 0; j--){
            vert = ((vec[i][j+1]) + 2);
            hori = ((vec[i+1][j]) + 2);
            diag = (ED::penalty(aString[i], bString[j]) + vec[i+1][j+1]);
            vec[i][j] = ED::min(vert, hori, diag);
        }
    }
    return vec[0][0];
}
//***************************************************************//

string ED::Alignment(){
    string ret = "";
    unsigned int i = 0;
    unsigned int j = 0;


    // loop for retrieving the alignment
    while((i < aString.length()) && (j < bString.length())){
        int p = ED::penalty(aString[i], bString[j]);

        if(vec[i][j] == vec[i+1][j+1]+p){
            ret += aString[i];
            ret += " ";
            ret += bString[j];
            ret += " ";
            ret += to_string(ED::penalty(aString[i], bString[j]));
            ret += "\n";
            i++;
            j++;
        } else if(vec[i][j] == vec[i+1][j] + 2){
            ret += aString[i];
            ret += " ";
            ret += "-";
            ret += " ";
            ret += "2";
            ret += "\n";
            i++;
        } else {
            ret += "-";
            ret += " ";
            ret += bString[j];
            ret += " ";
            ret += "2";
            ret += "\n";
            j++;
        }
    }

    // special case for things such as endgaps7 file.
    while((i < aString.length()) || (j < bString.length())){

        if(i < aString.length()){
            ret += aString[i];
            ret += " ";
            ret += "-";
            ret += " ";
            ret += "2";
            ret += "\n";
            i++;
        } else if(j < bString.length()){
            ret += "-";
            ret += " ";
            ret += bString[j];
            ret += " ";
            ret += "2";
            ret += "\n";
            j++;
        }
    }
    return ret;
}