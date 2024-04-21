// "Copyright [2018] <Scott Gordon>"

#include "LFSR.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

// constructor for LFSR
LFSR::LFSR(std::string seed, int t) {
    // set the tap, string, and reverse string so we can edit it properly
    reg = seed;
    reverse(reg.begin(), reg.end());
    tap = t;
}

// function for moving foward one step
int LFSR::step() {
std::string temp = "0";

    // XOR the last bit and the tap bit
    if(reg[(reg.length() - 1)] ^ reg[tap]) {
        temp = "1";
    }

    // change the string so it is 1 bit shorter, then add new bit
    reg = reg.substr(0, (reg.length() - 1));
    reg.insert(0, temp);

    // convert string to int for output
    int ret = stoi(temp, nullptr, 2);
    return ret;
}

// function for taking multiple steps at once
int LFSR::generate(int k) {
    int carry = 0;
    int temp = 0;
    // while there are still steps left to do, keep doing steps
    while(k >= 0) {
        temp = step();
        // add the bit * its dec value to the temp variable
        carry += (temp*pow(2, k-1));
        k--;
    }
    return carry;
}

// Override the ostream perator << to output the state of the register
std::ostream& operator<< (std::ostream &out, const LFSR &LFSR) {
    // Cycle through the register, outputting every bit
    for(unsigned int i = 0; i < LFSR.reg.length(); i++) {
        out << LFSR.reg[i];
    }
    return out;
}