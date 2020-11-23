#include <iostream>
#include "AlgorithmResult.hpp"
#include <cmath>
#include <vector>

unsigned int maxIterations = 200;

double exampleFunction (double x){
    return 3*x*x*x - 12*x - 2*x*x + 15;
    //return x*x - 29;
}

double exampleFunctionDerivative (double x){
    return 9*x*x - 4*x - 12;
    //return 2*x;
}


AlgorithmResult*  executeBisection (double (&f )(double), double epsilon, double x, double X);
AlgorithmResult*  executeRegulaFalsi (double (&f )(double), double epsilon, double x, double X);
AlgorithmResult*  executeNewton(double (&f )(double), double (&fDash )(double),double epsilon, double x);
AlgorithmResult*  executeSecantMethod(double (&f )(double), double epsilon, double x_last, double x_i);
AlgorithmResult*  executeExponentialApproach(double (&f )(double), double epsilon, double x_last, double x_i);
AlgorithmResult*  executeInverseSinusApproach(double (&f )(double), double (&fDash )(double),double epsilon, double x);

int main() {
    double (&f )(double) = exampleFunction;
    double (&fDash )(double) = exampleFunctionDerivative;
    double inital_val1 = 0;
    double inital_val2 = 14;
    std::vector<AlgorithmResult*> results;
    try {
        results.push_back(executeBisection(f, 0.0001, inital_val1, inital_val2));
        results.push_back(executeRegulaFalsi(f, 0.0001, inital_val1, inital_val2));
        results.push_back(executeNewton(f,fDash, 0.0001, inital_val2));
        results.push_back(executeInverseSinusApproach(f,fDash, 0.0001, inital_val2));
        results.push_back(executeSecantMethod(f, 0.0001,inital_val1, inital_val2));
        results.push_back(executeExponentialApproach(f, 0.0001,inital_val1, inital_val2));

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
    for (; i < maxIterations; i++){
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

    for (; i < maxIterations; i++){
        if (fx == 0 || std::abs(fx) < epsilon){
            break;
        }
        x = x - (fx / fDash(x));
        fx  = f(x);
    }
    return new AlgorithmResult("Newton", x, i, 0);
}

double calculateNextForSecant(double& x_i, double& x_last, double& fx_i, double& fx_last){
    return x_i - (x_i - x_last)/ (fx_i - fx_last) * fx_i;
}


AlgorithmResult*  executeSecantMethod(double (&f)(double) , double epsilon, double x_last, double x_i) {
    double fx_last = f(x_last);
    double fx_i = f(x_i);
    if ( fx_last * fx_i >= 0 ){
        throw std::invalid_argument( "[x0, x1] has to contain the root" );
    }
    unsigned int i = 1;
    double x_next;
    for (; i < maxIterations; i++){
        if (std::abs(fx_i) < epsilon){
            break;
        }
        x_next = calculateNextForSecant(x_i, x_last, fx_i,fx_last);
        x_last = x_i;
        x_i = x_next;

        fx_last = f(x_last);
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
    for (; i < maxIterations; i++){
        if (abs(fa) < epsilon || (X - x) < epsilon){
            break;
        }
        if (fa * fx < 0){
            X = a;
        } else {
            x = a;
        }
        a =  calculateNextForSecant(x,X,fx,fX);
        fa = f(a);
        fx = f(x);
        fX = f(X);
    }

    return new AlgorithmResult("Regula Falsi", a, i, 0);
}

AlgorithmResult *executeExponentialApproach(double (&f)(double) , double epsilon, double x_last, double x_i) {
    double fx_last = f(x_last);
    double fx_i = f(x_i);
    if ( fx_last * fx_i >= 0 ){
        throw std::invalid_argument( "[x0, x1] has to contain the root" );
    }
    unsigned int i = 1;
    double x_next, temp;
    for (; i < maxIterations; i++){
        if (std::abs(fx_i) < epsilon){
            break;
        }
        temp = (fx_i *(x_last - x_i )) / (x_i * (fx_i - fx_last));
        x_next = x_i * exp(temp);
        x_last = x_i;
        x_i = x_next;

        fx_last = f(x_last);
        fx_i = f(x_i);
    }
    return new AlgorithmResult("Exponentialreihe", x_i, i, 0);
}

AlgorithmResult *executeInverseSinusApproach(double (&f)(double) , double (&fDash)(double) , double epsilon, double x) {
    double fx = f(x);
    unsigned int i = 1;
    if (fDash(x) == 0 ){
        throw std::invalid_argument( "f'(x) cannot be zero" );
    }

    for (; i < maxIterations; i++){
        if (fx == 0 || std::abs(fx) < epsilon){
            break;
        }
        x = x * ( 1 + asin(-fx / (x * fDash(x))));
        fx  = f(x);
    }
    return new AlgorithmResult("Inverser Sinus", x, i, 0);
}
