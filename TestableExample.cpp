//
// Created by leoni on 15.10.2020.
//

#include <ostream>
#include <sstream>
#include "TestableExample.hpp"

funcPtr TestableExample::GetFunction() const{
    return function_;
}

double& TestableExample::GetFirstPoint() const {
    return a_;
}

double& TestableExample::GetEpsilon() const {
    return epsilon_;
}

double& TestableExample::GetSecondPoint() const {
    return b_;
}

void TestableExample::ResetExample() {
    a_ = start_a_;
    b_ = start_b_;
}

std::string TestableExample::ToString(int a) const{
    std::stringstream result;
    result << a_ << " | " << b_ << " | " << function_(a_) << " | " << function_(b_) << " |";
    return result.str();
}
