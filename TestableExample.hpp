//
// Created by leoni on 15.10.2020.
//

#ifndef PROGRAMMIERUNG_TESTABLEEXAMPLE_HPP
#define PROGRAMMIERUNG_TESTABLEEXAMPLE_HPP
typedef double (*funcPtr)(double);

class TestableExample {
public:
    TestableExample(double(*function)(double), double& a, double& b, double& epsilon) :
    function_{function}, a_{a}, b_{b},start_a_{a}, start_b_{b}, epsilon_{epsilon} {};
    std::string ToString(int a = 2) const;
    double& GetFirstPoint() const;
    double& GetSecondPoint() const;
    double& GetEpsilon() const;
    funcPtr GetFunction() const;
    void ResetExample();
private:
    double(*function_)(double);
    double& a_;
    double& b_;
    double& epsilon_;
    double start_a_;
    double start_b_;
};


inline std::ostream& operator<<(std::ostream& os, const TestableExample* to_print) {
    os << to_print->ToString();
    return os;
}
#endif //PROGRAMMIERUNG_TESTABLEEXAMPLE_HPP
