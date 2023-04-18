#include "Utils.h"

//Pseudo-random, but gets the job done.
const int Utils::GetRandomInt(int min, int max)
{
    std::srand(std::time(nullptr));
    
    int range = max - min + 1;
    int random_int = std::rand() % range + min;
    
    return random_int;
}
