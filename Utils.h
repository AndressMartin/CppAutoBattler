#pragma once

#include <ctime>
#include <random>
#include <iostream>

class Utils
{
public:
    static const int GetRandomInt(int min, int max);
    static const int GetRandomInt_MaxExclusive(int min, int max);
};