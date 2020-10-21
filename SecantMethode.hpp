//
// Created by leoni on 21.10.2020.
//

#ifndef PROGRAMMIERUNG_SECANTMETHODE_HPP
#define PROGRAMMIERUNG_SECANTMETHODE_HPP


#include "RootDeterminationAlgorithm.hpp"

class SecantMethode : public RootDeterminationAlgorithm  {
public:
    SecantMethode()
            : RootDeterminationAlgorithm( false)  {algName_ = "SecantMethode";};
    void RunAlgorithm(TestableExample* example) override;
private:

};
#endif //PROGRAMMIERUNG_SECANTMETHODE_HPP
