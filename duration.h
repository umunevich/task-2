// duration.h
#ifndef DURATION_H
#define DURATION_H

#include <vector>
#include <functional>

double measure_time(const std::function<void(const std::vector<int>& vector)>& func, const std::vector<int>& vector);

#endif