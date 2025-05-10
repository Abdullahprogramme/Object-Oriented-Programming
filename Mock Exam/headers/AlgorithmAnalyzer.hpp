#ifndef ALGORITHM_ANALYZER_HPP
#define ALGORITHM_ANALYZER_HPP

#include "Algorithm.hpp"
#include "BenchmarkResult.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <random>
#include <chrono>
#include <numeric>
#include <string>

using namespace std;

template<typename T>
class AlgorithmAnalyzer {
    private:
        vector<Algorithm<T>> algorithms;
        vector<BenchmarkResult> results;

    public:
        void registerAlgorithm(const Algorithm<T>& algo) {
            algorithms.push_back(algo);
        }

        void removeAlgorithm(const string& id) {
            algorithms.erase(remove_if(algorithms.begin(), algorithms.end(),
                [&](const Algorithm<T>& a) { return a.getId() == id; }), algorithms.end());
        }
        
        vector<Algorithm<T>> getAlgorithmsByCategory(const string& category) {
            return algorithms | std::ranges::views::filter([&](const Algorithm<T>& a) {
                return a.getCategory() == category;
            });
        }
            
        vector<Algorithm<T>> getAlgorithmsByComplexity(const string& timeComplexity) {
            return algorithms | std::ranges::views::filter([&](const Algorithm<T>& a) {
                return a.getTimeComplexity() == timeComplexity;
            });
        }

        void benchmarkAlgorithm(const string& id, int inputSize) {
            auto it = find_if(algorithms.begin(), algorithms.end(),
                                [&](const Algorithm<T>& a) { return a.getId() == id; });
            if (it == algorithms.end()) return;

            vector<T> data(inputSize);
            iota(data.begin(), data.end(), 1);
            shuffle(data.begin(), data.end(), mt19937(random_device{}()));

            auto copy = data;
            auto start = chrono::high_resolution_clock::now();
            it->getFunction()(copy);
            auto end = chrono::high_resolution_clock::now();

            results.push_back({id, inputSize, chrono::duration_cast<chrono::microseconds>(end - start), true});
        }

        void compareAlgorithms(const vector<string>& ids, int inputSize) {
            for (const auto& id : ids) {
                benchmarkAlgorithm(id, inputSize);
            }
        }

        void displayResults() const {
            for (const auto& res : results) {
                cout << "ID: " << res.algorithmId
                        << ", Size: " << res.inputSize
                        << ", Time: " << res.executionTime.count() << "us"
                        << ", Success: " << (res.success ? "Yes" : "No") << "\n";
            }
        }
};

#endif
