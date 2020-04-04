#pragma once

class RingBuffer {
    private:
        int capacity;
        double* values;
        int first;
        int last;

    public:
        RingBuffer(int capacity);
        ~RingBuffer();
        int size;
        bool isEmpty();
        bool isFull();
        void enqueue(double x);
        double dequeue();
        double peek();
};
