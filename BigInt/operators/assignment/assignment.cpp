#include "BigInt.hpp"
#include <string>


BigInt& BigInt::operator=(const BigInt &bi) {
    num = bi.num;
    sign = bi.sign;

    return *this;
}


BigInt& BigInt::operator= (char* num) {
    if (num[0] == '-') {
        sign = false;
        this->num = num;
        this->num = this->num.substr(1);
    } else {
        this->num = num;
        sign = true;
    }
    
    return *this;
}


BigInt& BigInt::operator= (long long num) {
    if (num < 0) {
        sign = false;
    }
    
    this->num = std::to_string(abs(num));
    
    return *this;
}
