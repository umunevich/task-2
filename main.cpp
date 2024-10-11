// main.cpp
// Created by Yana Utochkina

#include <random>
#include <iostream>

#include "policy.h"

void fillVector(std::vector<int> &vector, int size, int from, int to);

int main() {
    std::vector<int> vector;
    fillVector(vector, 1000000, 1, 20);
    std::ofstream outputFile("output.txt");
    // 1)
    no_policy(vector, outputFile);
    // 2)
    outputFile << "With policy: " << "Sequenced" << std::endl;
    std::execution::sequenced_policy pol;
    with_policy<std::execution::sequenced_policy>(pol, vector, outputFile);

    outputFile << "With policy: " << "Parallel" << std::endl;
    std::execution::parallel_policy par_pol;
    with_policy<std::execution::parallel_policy>(par_pol, vector, outputFile);

    outputFile << "With policy: " << "Unsequenced" << std::endl;
    std::execution::unsequenced_policy unseq_pol;
    with_policy<std::execution::unsequenced_policy>(unseq_pol, vector, outputFile);

    outputFile << "With policy: " << "Parallel unsequenced" << std::endl;
    std::execution::parallel_unsequenced_policy par_unseq_pol;
    with_policy<std::execution::parallel_unsequenced_policy>(par_unseq_pol, vector, outputFile);
    // 3)
    std::ofstream resultTable("result.csv");
    resultTable << "K; Time" << std::endl;
    std::cout << std::thread::hardware_concurrency() << std::endl;
    for (int i = 1; i <= std::thread::hardware_concurrency(); i++) {
        outputFile << "Custom policy: " << i << " threads. Time: ";
        custom_policy(vector, i, outputFile, resultTable);
    }
}

void fillVector(std::vector<int> &vector, const int size, const int from, const int to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);
    for (int i = 0; i < size; i++) {
        vector.push_back(dist(gen));
    }
}