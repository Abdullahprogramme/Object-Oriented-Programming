#include "ExpressionEvaluator.hpp"
#include "Add.hpp"
#include "Multiply.hpp"
#include "ExpensivePower.hpp"
#include "CachedAdd.hpp"
#include "CachedMultiply.hpp"
#include "CachedSine.hpp"
#include "Operation.hpp"
#include <iostream>

using namespace std;

int main() {
    ExpressionEvaluator<double> evaluator;

    Add<double>* addOperation = new Add<double>(5); 
    ExpensivePower<double>* powerOperation = new ExpensivePower<double>(2);
    CachedSine<double>* sineOperation = new CachedSine<double>();
    CachedAdd<double>* cachedAddOperation = new CachedAdd<double>();

    evaluator.addOperation(addOperation); // Running answer: 5 + 3 = 8
    evaluator.addOperation(new CachedSine<double>());
    evaluator.addOperation(powerOperation); // Running answer: (3 + 5)^2 = 64
    evaluator.addOperation(cachedAddOperation); // 64 + 0 = 64
    evaluator.addOperation(cachedAddOperation); // 64 + 64 = 128

    evaluator.printPipeline();

    double input = 3.0;
    double result = evaluator.evaluate(input);
    cout << "Final result: " << result << endl;

    return 0;
}