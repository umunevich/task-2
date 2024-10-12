// policy.cpp
// Created by Yana Utochlina

#include "policy.h"

void no_policy(std::vector<int>& vector, std::ofstream& output) {
    output << "Policy: No. " << std::endl;
    std::pair<std::chrono::nanoseconds, bool> result = measure_time([&vector]() {
        return std::any_of(vector.begin(), vector.end(),[](int el) {
            return pred(el);
        });
    });
    output << "Time: " << result.first.count() << "ns " << "Result: " << std::boolalpha << result.second << std::endl << std::endl;
}

std::pair<std::chrono::nanoseconds, bool> measure_time(const std::function<bool()>& function) {
    const auto start = std::chrono::system_clock::now();
    bool result = function();
    const auto end = std::chrono::system_clock::now();
    auto duration = end - start;
    return std::make_pair(duration, result);
}

bool pred(int el) {
#ifdef PRED_LESS_THEN_ZERO
    return el < 0;
#endif
#ifdef  PRED_IS_EVEN
    return el % 2 == 0;
#else
    return el > 0;
#endif
}

void particular_proccessing(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<bool>::iterator curr) {
    *curr = std::any_of(/*std::execution::seq,*/ begin, end, [&](int el) {
        return pred(el);
    });
}

void custom_policy(std::vector<int>& vector, int K, std::ofstream& output, std::ofstream& resultTable) {
    int part_size = vector.size() / K;

    const auto start = std::chrono::system_clock::now();
    std::vector<std::thread> threads;
    std::vector<bool> results(K);
    for (int i = 0; i < K - 1; i++) {
        threads.emplace_back(particular_proccessing, vector.begin() + (i * part_size), vector.begin() + ((i + 1) * part_size), results.begin()+i);
    }
    threads.emplace_back(particular_proccessing, vector.begin() + ((K - 1) * part_size), vector.end(), results.begin()+(K-1));
    for (int i = 0; i < K; i++) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }
    const bool result = std::any_of(results.begin(), results.end(), [&](bool el) {
        return el;
    });

    const auto end = std::chrono::system_clock::now();
    auto duration = end - start;

    resultTable << K << ", " << duration.count() << std::endl;
    output << duration.count() << "ns. Result: " << result << std::endl;
}