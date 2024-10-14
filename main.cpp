// main.cpp
// Created by Yana Utochkina

#include <random>

#include "policy.h"

const int FROM = 1;
const int TO = 20;
const int SIZE = 100000000; // 100000000 "ln(1/x)", 60000 "x^2", 700 "ln(x)"

void fillVector(std::vector<int> &vector);
void task_info(std::ofstream &output);

int main() {
    std::vector<int> vector;
    std::ofstream outputFile("output.txt");

    task_info(outputFile);
    fillVector(vector);
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
    for (int i = 1; i <= std::thread::hardware_concurrency(); i++) {
        outputFile << "Custom policy: " << i << " threads. Time: ";
        custom_policy(vector, i, outputFile, resultTable);
    }
}

void task_info(std::ofstream &output) {
    output << "Test data: vector<int>(" << SIZE << "), where values from " << FROM << " to " << TO << ". " << std::endl;
    output << "Operation: std::any_of. " << std::endl;
    output << std::endl;
}

void fillVector(std::vector<int> &vector) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(FROM, TO);
    for (int i = 0; i < SIZE; i++) {
        vector.push_back(dist(gen));
    }
}