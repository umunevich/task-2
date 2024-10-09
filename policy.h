// policy.h
// Created by Yana Utochkina

#ifndef POLICY_H
#define POLICY_H

#include <fstream>
#include <vector>
#include <chrono>
#include <functional>

enum class execution {seq, par, unseq, par_unseq};

void no_policy(std::vector<int>& vector, std::ofstream& output);
std::pair<std::chrono::nanoseconds, bool> measure_time(const std::function<bool()>& function);
bool pred(int el);

// Above defined different predicates.
#define PRED_LESS_THEN_ZERO
//#define PRED_IS_EVEN

#endif