#include "BigInt.hpp"


BigInt BigInt::operator + () {
    return *this;
}


BigInt BigInt::operator - () const {
    BigInt tmp = *this;
    
    if (tmp.num != "0") {
        tmp.sign = !sign;
    }
    
    return tmp;
}
