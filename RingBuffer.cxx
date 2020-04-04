#include "RingBuffer.h"

RingBuffer::RingBuffer(int capacity) : capacity(capacity), size(0), first(0), last(0) {
    values = new double[capacity];
}

RingBuffer::~RingBuffer(){
    delete[] values;
}


bool RingBuffer::isEmpty(){
    return size==0;
}

bool RingBuffer::isFull(){
    return size==capacity;
}

void RingBuffer::enqueue(double x){
    values[last] = x;
    last = (last + 1 == capacity ? 0 : last + 1);
}

double RingBuffer::dequeue(){
    int _first = first;
    first = (first + 1 == capacity ? 0 : first + 1);
    return values[_first];
}

double RingBuffer::peek(){
    return values[first];
}