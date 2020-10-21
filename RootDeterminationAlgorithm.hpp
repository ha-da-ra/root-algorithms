//
// Created by leoni on 12.10.2020.
//

#ifndef PROGRAMMIERUNG_ROOTDETERMINATIONALGORITHM_HPP
#define PROGRAMMIERUNG_ROOTDETERMINATIONALGORITHM_HPP
#include <string>
#include "TestableExample.hpp"

class RootDeterminationAlgorithm {
public:
    explicit RootDeterminationAlgorithm( bool zeroInIntervallRequired = true) :  zeroInIntervalRequired_{zeroInIntervallRequired}{};
    bool ExampleWorksForAlg(TestableExample* example);
    std::string GetName();
    virtual void RunAlgorithm(TestableExample* example) = 0;
protected:
    bool zeroInIntervalRequired_{true};
    std::string algName_{""};
};



#endif //PROGRAMMIERUNG_ROOTDETERMINATIONALGORITHM_HPP
