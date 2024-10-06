// main.cpp
#include <iostream>
#include <chrono>
#include <functional>
#include "algos.h"

void fill_vector(std::vector<int>& vector);
std::pair<double, bool> measure_time(const std::function<bool(const std::vector<int>& vector)>& func, const std::vector<int>& vector);

int main() {
    std::vector<int> vector100(100);
    fill_vector(vector100);

    auto pair = measure_time(without_politic, vector100);
    std::cout << "Time: " << pair.first << " Result: " << std::boolalpha << pair.second << std::endl;


    return 0;
}

void fill_vector(std::vector<int>& vector) {
    for (auto &it : vector) {
        it = rand() % vector.size();
    }
}

std::pair<double, bool> measure_time(const std::function<bool(const std::vector<int>& vector)>& func, const std::vector<int>& vector) {
    bool result;
    const auto start = std::chrono::system_clock::now();

    result = func(vector);

    const auto end = std::chrono::system_clock::now();
    const auto duration = std::chrono::duration<double>{end - start};
    return std::pair<double, bool>{duration.count(), result};
}

