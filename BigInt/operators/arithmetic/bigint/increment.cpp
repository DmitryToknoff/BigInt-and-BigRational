#include "BigInt.hpp"


BigInt& BigInt::operator++ () {
    *this += 1;
    
    return *this;
}

BigInt BigInt::operator++ (int) {
    BigInt tmp = *this;
    
    *this += 1;
    
    return tmp;
}
