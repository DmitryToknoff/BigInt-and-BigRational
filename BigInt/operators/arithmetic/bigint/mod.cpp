#include "BigInt.hpp"
#include <string>



BigInt BigInt::operator % (const BigInt& bi) const {
    if (bi.num == "0") {
        throw std::invalid_argument("Division by zero");
    }
    
    BigInt abs_divid = abs(*this);
    BigInt abs_divisor = abs(bi);
    
    if (abs_divid < abs_divisor) {
        return *this;
    }
    
    BigInt quotient = abs_divid / abs_divisor;
    
    BigInt remainder = abs_divid - (abs_divisor * quotient);
    
    remainder.sign = this->sign;
    
    if (remainder.num == "0") remainder.sign = true;
    
    return remainder;
}

BigInt& BigInt::operator %= (const BigInt& bi) {
    BigInt tmp = *this % bi;
    
    num = tmp.num;
    sign = tmp.sign;
    
    
    return *this;
}

