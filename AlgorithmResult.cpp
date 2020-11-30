//
// Created by Leonie on 19.11.2020.
//
#include <iostream>
#include <iomanip>

#include "AlgorithmResult.hpp"
void AlgorithmResult::to_stream(std::ostream &os) const {
    os << std::setw(18) << std::left << name_ << " | ";
    os << std::setw(8)  << std::right << rootResult_ << " | ";
    os << std::setw(3)  << iterations_ << " | ";
}

double AlgorithmResult::getResult() const {
    return rootResult_;
}
