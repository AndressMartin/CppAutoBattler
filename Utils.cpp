#include <random>
#include "Utils.h"

//Pseudo-random, but gets the job done.
int Utils::GetRandomInt(int min, int max)
{
    static std::random_device rd; // Initialize a random device only once
    static std::mt19937 gen(rd()); // Initialize a random number generator (Mersenne Twister) with the random device

    std::uniform_int_distribution<> dis(min, max); // Define a uniform distribution between min and max

    return dis(gen); // Generate a random integer within the specified range
}

int Utils::GetRandomInt_MaxExclusive(int min, int max)
{
    return GetRandomInt(min, max-1);
}