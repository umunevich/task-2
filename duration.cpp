#include <chrono>
#include <functional>

double measure_time(const std::function<void(const std::vector<int>&)>& func, const std::vector<int>& vector) {
    const auto start = std::chrono::system_clock::now();

    func(vector);

    const auto end = std::chrono::system_clock::now();
    const auto duration = std::chrono::duration<double>{end - start};
    return duration.count();
}
