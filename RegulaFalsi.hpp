//
// Created by leoni on 14.10.2020.
//

#ifndef PROGRAMMIERUNG_REGULAFALSI_HPP
#define PROGRAMMIERUNG_REGULAFALSI_HPP


#include "RootDeterminationAlgorithm.hpp"

class RegulaFalsi : public RootDeterminationAlgorithm  {
public:
    RegulaFalsi()
            : RootDeterminationAlgorithm(true)  {algName_ = "RegulaFalsi";};
    void RunAlgorithm(TestableExample* example) override;
private:

};


#endif //PROGRAMMIERUNG_REGULAFALSI_HPP
