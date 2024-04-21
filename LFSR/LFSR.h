// "Copyright [2018] <Scott Gordon>"

#ifndef _HOME_OSBOXES_COMP2040_SFML_PS2A_LFSR_H_
#define _HOME_OSBOXES_COMP2040_SFML_PS2A_LFSR_H_
#pragma once

#include <string>

class
LFSR {
    public:
    LFSR(std::string seed, int t); // constructor to create LFSR with
    // the given initial seed and tap
    int step(); // simulate one step and return the
    // new bit as 0 or 1
    int generate(int k); // simulate k steps and return
    // k-bit integer
    // making the overloaded operator a friend of the
    // class so that it has access to the private members
    friend std::ostream& operator<< (std::ostream &out, const LFSR
    &LFSR);

    private:
    std::string reg;
    int tap;
};

#endif