// policy.h
// Created by Yana Utochkina

#ifndef POLICY_H
#define POLICY_H

#include <fstream>
#include <vector>
#include <chrono>
#include <functional>
#include <execution>
#include <thread>

// Above defined different predicates.
#define PRED_LESS_THEN_ZERO
//#define PRED_IS_EVEN

#endif

void no_policy(std::vector<int>& vector, std::ofstream& output);

std::pair<std::chrono::nanoseconds, bool> measure_time(const std::function<bool()>& function);

bool pred(int el);

template <typename Policy>
void with_policy(Policy policy, std::vector<int>& vector, std::ofstream& output) {
    std::pair<std::chrono::nanoseconds, bool> result = measure_time([&vector, policy]() {
        return std::any_of(policy, vector.begin(), vector.end(),[](int el) {
            return pred(el);
        });
    });
    output << "Time: " << result.first.count() << "ns " << "Result: " << std::boolalpha << result.second << std::endl << std::endl;
}

void custom_policy(std::vector<int>& vector, int K, std::ofstream& output, std::ofstream& resultTable);
