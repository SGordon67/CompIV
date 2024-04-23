// "Copyright 2018 Scott Gordon"

#include "RingBuffer.hpp"
#include <stdint.h>
#include <vector>
#include <iostream>
#include <queue>
#include <stdexcept>

RingBuffer::RingBuffer(int capacity) {
    if(capacity == 0) {
        throw std::invalid_argument("Capacity must be greater than zero.");
    }
    this->cap = capacity;
}
int RingBuffer::size() {
    return this->buffer.size();
}
bool RingBuffer::isEmpty() {
    return this->buffer.empty();
}
bool RingBuffer::isFull() {
    return(this->buffer.size() == this->cap);
}
void RingBuffer::enqueue(int16_t x) {
    if(this->buffer.size() == this->cap) {
        throw(std::runtime_error("Can't enqueue to a full ring."));
    }
    this->buffer.push(x);
}
int16_t RingBuffer::dequeue() {
    if(this->buffer.size() == 0) {
        throw std::runtime_error("Can't dequeue from an empty ring.");
    }
    int16_t ret;
    ret = this->buffer.front();
    this->buffer.pop();
    return ret;
}
int16_t RingBuffer::peek() {
    if(this->buffer.size() == 0) {
        throw std::runtime_error("Can't dequeue from an empty ring.");
    }
    return this->buffer.front();
}