#include <iostream>
#include "AlgorithmResult.hpp"
#include <cmath>
#include <vector>

double squareRootOfTwo (double x){
    return x*x - 2;
}

double squareRootOfTwoDerivative(double x){
    return 2*x;
}

AlgorithmResult*  executeBisection (double (&f )(double), double epsilon, double x, double X);
AlgorithmResult*  executeRegulaFalsi (double (&f )(double), double epsilon, double x, double X);
AlgorithmResult*  executeNewton(double (&f )(double), double (&fDash )(double),double epsilon, double x);
AlgorithmResult*  executeSecantMethod(double (&f )(double), double epsilon, double x_i_less_1, double x_i);


int main() {
    double (&f )(double) = squareRootOfTwo;
    double (&fDash )(double) = squareRootOfTwoDerivative;
    std::vector<AlgorithmResult*> results;
    try {
        results.push_back(executeBisection(f, 0.0001, 0, 3));
        results.push_back(executeRegulaFalsi(f, 0.0001, 0, 3));
        results.push_back(executeNewton(f,fDash, 0.0001, 3));
        results.push_back(executeSecantMethod(f, 0.0001,0, 3));

        for(auto result : results){
            std::cout << *result << std::endl;
        }
    } catch (std::invalid_argument& err){
        std::cout << err.what();
    }
    for (auto result : results){
        delete result;
    }
    return 0;
}

AlgorithmResult* executeBisection(double (&f)(double), double epsilon, double x, double X) {
    double fx = f(x);
    double fX = f(X);
    if ( fx * fX >= 0 || X <= x){
        throw std::invalid_argument( "x and X were not chosen properly" );
    }

    double a = (x + X) / 2;
    double fa = f(a);
    unsigned int i = 1;
    for (; i < 100; i++){
        if (fa == 0 || X - x < epsilon){
            break;
        }
        if (fa * fx < 0){
            X = a;
        } else {
            x = a;
        }
        a = (x + X) / 2;
        fa = f(a);
    }

    return new AlgorithmResult("Bisektion", a, i, 0);
}

AlgorithmResult*  executeNewton(double (&f)(double) , double (&fDash)(double) , double epsilon, double x) {
    double fx = f(x);
    unsigned int i = 1;
    if (fDash(x) == 0 ){
        throw std::invalid_argument( "f'(x) cannot be zero" );
    }

    for (; i < 100; i++){
        if (fx == 0 || std::abs(fx) < epsilon){
            break;
        }
        x = x - (fx / fDash(x));
        fx  = f(x);
    }
    return new AlgorithmResult("Newton", x, i, 0);
}

AlgorithmResult*  executeSecantMethod(double (&f)(double) , double epsilon, double x_i_less_1, double x_i) {
    double fx_i_less_1 = f(x_i_less_1);
    double fx_i = f(x_i);
    if ( fx_i_less_1 * fx_i >= 0 ){
        throw std::invalid_argument( "[x0, x1] has to contain the root" );
    }
    unsigned int i = 1;
    double x_next;
    for (; i < 100; i++){
        if (std::abs(fx_i) < epsilon){
            break;
        }
        x_next = x_i - (x_i - x_i_less_1)/ (fx_i - fx_i_less_1) * fx_i;
        x_i_less_1 = x_i;
        x_i = x_next;

        fx_i_less_1 = f(x_i_less_1);
        fx_i = f(x_i);
    }
    return new AlgorithmResult("Sekantenverfahren", x_i, i, 0);
}

AlgorithmResult*  executeRegulaFalsi(double (&f)(double) , double epsilon, double x, double X) {
    double fx = f(x);
    double fX = f(X);
    if ( fx * fX >= 0 || X <= x){
        throw std::invalid_argument( "x and X were not chosen properly" );
    }

    double a = x - (x - X)/ (fx - fX) * fx;
    double fa = f(a);
    unsigned int i = 1;
    for (; i < 100; i++){
        if (fa == 0 || X - x < epsilon){
            break;
        }
        if (fa * fx < 0){
            X = a;
        } else {
            x = a;
        }
        a =  x - (x - X)/ (fx - fX) * fx;
        fa = f(a);
        fx = f(x);
        fX = f(X);
    }

    return new AlgorithmResult("Regula Falsi", a, i, 0);
}
