#include <iostream>
#include <cmath>
#include <vector>
#include "Bisection.hpp"
#include "RegulaFalsi.hpp"
#include "AlgorithmTester.hpp"
#include "SecantMethode.hpp"

double exampleSecondOrder (double x){
    return x*x - 4*x + 3;
}

double exampleFourthOrder (double x){
    return 3 * pow(x,4) - 2.5 * pow(x,3) - 32.2;
}


int main() {
    std::cout << "Algorithm Tester" << std::endl;
    std::cout << "=========" << std::endl;

    AlgorithmTester Tester;
    //Tester.AddAlgorithm(new Bisection());
    //Tester.AddAlgorithm(new RegulaFalsi());
    Tester.AddAlgorithm(new SecantMethode());
    double a1 = 2.0; double b1 = 6; double epsilon = 0.01;
    double a2 = 0; double b2 = 12;
    Tester.AddExample(new TestableExample(&exampleFourthOrder, a1,b1, epsilon ));
    Tester.AddExample(new TestableExample(&exampleFourthOrder, a2,b2, epsilon ));
    Tester.TestAlgorithms();
    return 0;
}

