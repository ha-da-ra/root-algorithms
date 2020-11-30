//
// Created by Leonie on 19.11.2020.
//

#ifndef ROOT_ALGORITHMS_ALGORITHMRESULT_HPP
#define ROOT_ALGORITHMS_ALGORITHMRESULT_HPP

#include <string>

class AlgorithmResult {
public:
    AlgorithmResult(std::string algName, double result, unsigned int iterations)
    : name_{algName}, rootResult_{result}, iterations_{iterations}{};
    void to_stream(std::ostream& os) const;
    double getResult() const;
private:
    std::string name_;
    double rootResult_;
    unsigned int iterations_;
};


inline std::ostream& operator<<(std::ostream& os, const AlgorithmResult& result) {
    result.to_stream(os);
    return os;
}

#endif //ROOT_ALGORITHMS_ALGORITHMRESULT_HPP
