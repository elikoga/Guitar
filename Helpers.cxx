#include <random>

#include "Helpers.h"

double fRand(double min, double max){
    std::uniform_real_distribution<double> unif(min, max);
    std::default_random_engine re;
    return unif(re);
}