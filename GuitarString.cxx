#include <cmath>

#include "GuitarString.h"
#include "RingBuffer.h"
#include "Helpers.h"

#define SAMPLERATE 44100

GuitarString::GuitarString(double frequency) : time(0) {
    size = std::ceil(SAMPLERATE/frequency);
    rb = new RingBuffer(size);
    for(int i = 0; i < size; i++){
        rb->enqueue(0);
    }
}

GuitarString::GuitarString(double init[], int size) : time(0), size(size) {
    rb = new RingBuffer(size);
    for(int i = 0; i < size; i++){
        rb->enqueue(init[i]);
    }
}
GuitarString::~GuitarString(){
    delete rb;
}
void GuitarString::pluck(){
    for(int i = 0; i < size; i++){
        rb->enqueue(fRand(-0.5, 0.5));
    }
}
void GuitarString::tic(){
    double val;
    val = 0.994 * 0.5 * (rb->dequeue()+rb->peek());
    time++;
    rb->enqueue(val);
}
double GuitarString::sample(){
    return rb->peek();
}
