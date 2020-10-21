//
// Created by leoni on 14.10.2020.
//

#include <stdexcept>
#include "RootDeterminationAlgorithm.hpp"


std::string RootDeterminationAlgorithm::GetName() {
    return algName_;
}

bool RootDeterminationAlgorithm::ExampleWorksForAlg(TestableExample *example) {
    if (example->GetFunction()(example->GetFirstPoint())
        * example->GetFunction()(example->GetSecondPoint())
        > 0 && this->zeroInIntervalRequired_){
        return false;
    }
    return true;
}

