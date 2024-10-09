// main.cpp
// Created by Yana Utochkina

#include <random>
#include "policy.h"

void fillVector(std::vector<int> &vector, int size, int from, int to);

int main() {
    std::vector<int> vector;
    fillVector(vector, 1000000, 1, 20);
    std::ofstream outputFile("output.txt");
    no_policy(vector, outputFile);
}

void fillVector(std::vector<int> &vector, int size, int from, int to) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(from, to);
    for (int i = 0; i < size; i++) {
        vector.push_back(dist(gen));
    }
}