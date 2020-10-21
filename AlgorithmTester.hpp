//
// Created by leoni on 15.10.2020.
//

#ifndef PROGRAMMIERUNG_ALGORITHMTESTER_HPP
#define PROGRAMMIERUNG_ALGORITHMTESTER_HPP


#include <vector>
#include "RootDeterminationAlgorithm.hpp"
#include "TestableExample.hpp"

class AlgorithmTester {
public:
    AlgorithmTester();
    void AddAlgorithm(RootDeterminationAlgorithm* alg);
    void AddExample(TestableExample* alg);
    void TestAlgorithms();
    ~AlgorithmTester();
private:
    std::vector<RootDeterminationAlgorithm*> algorithms_;
    std::vector<TestableExample*> examples_;

    bool ZeroWasFound(TestableExample *pExample);
};


#endif //PROGRAMMIERUNG_ALGORITHMTESTER_HPP
