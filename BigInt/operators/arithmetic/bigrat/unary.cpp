#include "BigInt.hpp"
#include "BigRat.hpp"




BigRational BigRational::operator + () {
    return *this;
}


BigRational BigRational::operator - () {
    if (num.get_sign() + dem.get_sign() == 2 || num.get_sign() + dem.get_sign() == 0) {
        BigRational res = *this;
        res.num.set_sign(false);
        
        return res;
    }
    
    return *this;
}
