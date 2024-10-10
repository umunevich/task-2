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
#elif  PRED_IS_EVEN
    return el % 2 == 0;
#else
    return el > 0;
#endif
}