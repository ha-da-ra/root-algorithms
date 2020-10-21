//
// Created by leoni on 12.10.2020.
//

#include <stdexcept>
#include "Bisection.hpp"


void Bisection::RunAlgorithm(TestableExample *example) {
    auto function = example->GetFunction();
    double& a = example->GetFirstPoint();
    double& b = example->GetSecondPoint();
    double& epsilon = example->GetEpsilon();

    double x = (a + b)/ 2;
    if (function(x) * function(a) < 0) {
        b = x;
    } else {
        a = x;
    }
}
