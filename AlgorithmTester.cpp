//
// Created by leoni on 15.10.2020.
//

#include <iostream>
#include "AlgorithmTester.hpp"
#include <limits>       // std::numeric_limits
void AlgorithmTester::AddAlgorithm(RootDeterminationAlgorithm *alg) {
    algorithms_.push_back(alg);
}

void AlgorithmTester::AddExample(TestableExample *example) {
    examples_.push_back(example);
}

AlgorithmTester::~AlgorithmTester() {
    for (auto* alg : algorithms_){
        delete alg;
    }
    for (auto* example : examples_){
        delete example;
    }

}

void AlgorithmTester::TestAlgorithms() {
    for (auto* alg : algorithms_){
        for (auto* example : examples_){
            int iterations = 0;
            std::cout << std::endl << "# " << alg->GetName() << std::endl;
            std::cout << "| index | a | b | f(a) | f(b) |" << std::endl;
            std::cout << "| ---- | ---- | ----| --- | ----- |" << std::endl;
            while (true){
                if (ZeroWasFound(example) || iterations > 100 ){
                    std::cout << "| " << iterations << " | " << example << std::endl;
                    break;
                } else if (ReachedLimit(example)){
                    std::cout << "| " << iterations << " | " << example << std::endl;
                    std::cout << "ABORTED: one of the points reached the defined limit" << std::endl;
                    break;
                } else {
                    std::cout << "| " << iterations << " | " << example << std::endl;
                    alg->RunAlgorithm(example);
                    iterations++;
                }
            }
            example->ResetExample();
        }
    }

}

bool AlgorithmTester::ZeroWasFound(TestableExample *pExample) {
    return std::abs(pExample->GetFunction()(pExample->GetFirstPoint())) <= pExample->GetEpsilon()
           || std::abs(pExample->GetFunction()(pExample->GetSecondPoint())) <= pExample->GetEpsilon();
}

bool AlgorithmTester::ReachedLimit(TestableExample *pExample) {
    return std::abs(pExample->GetFirstPoint()) == std::numeric_limits<double>::infinity()
            || std::abs(pExample->GetSecondPoint()) == std::numeric_limits<double>::infinity();
}

AlgorithmTester::AlgorithmTester() = default;
