#pragma once
#include "RingBuffer.h"

class GuitarString{
    private:
        RingBuffer* rb;
        int size;

    public:
        GuitarString(double frequency);
        GuitarString(double init[], int size);
        ~GuitarString();
        void pluck();
        void tic();
        double sample();
        int time;
};