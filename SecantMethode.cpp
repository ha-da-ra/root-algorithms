//
// Created by leoni on 21.10.2020.
//

#include "SecantMethode.hpp"

void SecantMethode::RunAlgorithm(TestableExample *example) {
    auto f = example->GetFunction();
    double& x0 = example->GetFirstPoint();
    double& x1 = example->GetSecondPoint();
    double& epsilon = example->GetEpsilon();

    double x2 = x1 - f(x1) * (x1 - x0) / float(f(x1) - f(x0));
    x0 = x1;
    x1 = x2;

}
