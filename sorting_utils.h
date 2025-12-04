#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <algorithm>
#include <chrono>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <vector>

// Data pattern used to initialize test arrays.
enum class DataPattern { Random, Sorted, Reversed };

// Returns a human-readable label for the selected pattern.
inline std::string_view patternLabel(DataPattern pattern) {
    switch (pattern) {
        case DataPattern::Random:
            return "aleatorio";
        case DataPattern::Sorted:
            return "ordenado";
        case DataPattern::Reversed:
            return "inverso";
    }
    return "";
}

// Shared random engine for reproducible and portable random numbers.
inline std::mt19937& randomEngine() {
    static std::mt19937 engine(std::random_device{}());
    return engine;
}

// Generates an integer within the provided range using the shared engine.
inline int randomInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(randomEngine());
}

// Creates an integer vector following the requested pattern.
inline std::vector<int> makeArray(int size, DataPattern pattern) {
    std::vector<int> arr(size);
    switch (pattern) {
        case DataPattern::Sorted:
            std::iota(arr.begin(), arr.end(), 0);
            break;
        case DataPattern::Reversed:
            std::iota(arr.begin(), arr.end(), 1);
            std::reverse(arr.begin(), arr.end());
            break;
        case DataPattern::Random:
        default:
            std::generate(arr.begin(), arr.end(), [size]() { return randomInt(0, std::max(size, 1)); });
            break;
    }
    return arr;
}

// Convenience alias for high-resolution timestamps.
using Clock = std::chrono::high_resolution_clock;

#endif  // SORTING_UTILS_H
