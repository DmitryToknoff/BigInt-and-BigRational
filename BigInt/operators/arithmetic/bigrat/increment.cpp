#include "BigRat.hpp"
#include "BigInt.hpp"

BigRational& BigRational::operator++ () {
    num += dem;
    
    return *this;
}


BigRational BigRational::operator ++ (int) {
    BigRational res = *this;
    
    num += dem;
    
    return res;
}
