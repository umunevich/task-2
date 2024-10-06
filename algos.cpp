// algos.cpp
#include <algorithm>
#include "algos.h"

bool pred(int el) {
    return !(el - 90)%10;
}

bool without_politic(const std::vector<int>& vector) {
    return std::any_of(vector.begin(), vector.end(), [](int i){return pred(i);});
}