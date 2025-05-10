#ifndef BENCHMARK_RESULT_HPP
#define BENCHMARK_RESULT_HPP

#include <chrono>
#include <string>

using namespace std;

struct BenchmarkResult {
    string algorithmId;
    int inputSize;
    chrono::microseconds executionTime;
    bool success;
};

#endif
