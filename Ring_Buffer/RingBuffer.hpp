// "Copyright 2018 Scott Gordon"

#ifndef Body_INCLUDE
#define Body_INCLUDE
#pragma once

#include <stdint.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <boost/circular_buffer.hpp>

class RingBuffer{
    public:
    // create an empty ring buffer, with given max capacity
    RingBuffer(int capacity);
    int size(); // return number of items currently in the buffer
    bool isEmpty(); // is the buffer empty (size equals zero)?
    bool isFull(); // is the buffer full (size equals capacity)?
    void enqueue(int16_t x); // add item x to the end
    int16_t dequeue(); // delete and return item from the front
    int16_t peek(); // return (but do not delete) item from the front
    
    private:
    std::queue<int16_t> buffer;
    unsigned int cap;
};

#endif