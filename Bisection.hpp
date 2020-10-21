//
// Created by leoni on 12.10.2020.
//

#ifndef PROGRAMMIERUNG_BISECTION_HPP
#define PROGRAMMIERUNG_BISECTION_HPP


#include "RootDeterminationAlgorithm.hpp"

class Bisection : public RootDeterminationAlgorithm {
public:
    Bisection( )
    : RootDeterminationAlgorithm( true)  {algName_ = "Bisection";};
    void RunAlgorithm(TestableExample* example) override;
private:

};


#endif //PROGRAMMIERUNG_BISECTION_HPP
