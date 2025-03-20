#include "BigInt.hpp"
#include "BigRat.hpp"
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


BigRational& BigRational::operator=(int x) {
    num = x;
    dem = 1;
    
    return *this;
}

BigRational& BigRational::operator=(const BigRational& br) {
    num = br.num;
    dem = br.dem;
    
    
    return *this;
}

BigRational& BigRational::operator=(const BigInt& bi) {
    num = bi;
    dem = 1;
    
    return *this;
}
