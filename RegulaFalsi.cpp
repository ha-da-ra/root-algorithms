//
// Created by leoni on 14.10.2020.
//

#include <cmath>
#include "RegulaFalsi.hpp"


void RegulaFalsi::RunAlgorithm(TestableExample *example) {
    auto function = example->GetFunction();
    double& a = example->GetFirstPoint();
    double& b = example->GetSecondPoint();
    double& epsilon = example->GetEpsilon();

    double x = a - ((b-a)/(function(b)-function(a)))*function(a);
    if (function(x) * function(a) < 0) {
        b = x;
    } else {
        a = x;
    }

}
