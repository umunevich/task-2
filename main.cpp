// main.cpp
#include <iostream>
#include "duration.h"
#include "algos.h"

int main() {
    std::vector<int> vec1 = {10, 2, 4, 1, 8, 3, 2 , 4 , 1 , 5 , 6 , 7 , 8 , 9};

    std::cout << measure_time(without_politic, vec1) << std::endl;
    return 0;
}