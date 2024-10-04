// algos.cpp
#include <algorithm>
#include "algos.h"
void without_politic(const std::vector<int>& vector) {
    std::any_of(vector.begin(), vector.end(),[](int i) {
        return i%2;
    });
}