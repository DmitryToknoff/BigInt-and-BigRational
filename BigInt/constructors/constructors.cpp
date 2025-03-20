#include "BigInt.hpp"
#include "BigRat.hpp"

#include <iostream>
#include <string>


BigInt::BigInt() {
    sign = true;
    num = "0";
}


BigInt::BigInt(const BigInt& bi) {
    this->sign = bi.sign;
    this->num = bi.num;
}

BigInt::BigInt(const std::string& s) {
    if (s[0] == '-') {
        sign = false;
        num = s.substr(1);
    } else
        num = s;
}


BigInt::BigInt(char* s) {
    if (s[0] == '-') {
        sign = false;
        num = s;
        num = num.substr(1);
        
    } else {
        num = s;
    }
}


BigInt::BigInt(long long num) {
    if (num < 0) {
        sign = false;
    }
    
    this->num = std::to_string(abs(num));
}


BigInt::BigInt(int num) {
    if (num < 0)
        sign = false;
    
    this->num = std::to_string(abs(num));
}


BigRational::BigRational() {
    num = "0";
    dem = "1";
}


BigRational::BigRational(const BigInt& bi) {
    num = bi;
    dem = 1;
}


BigRational::BigRational(const BigRational& br) {
    num = br.num;
    dem = br.dem;
}

BigRational::BigRational(int num) {
    this->num = num;
    dem = 1;
}

BigRational::BigRational(long long num) {
    this->num = num;
    dem = 1;
}

BigRational::BigRational(const BigInt& num, const BigInt& dem) {
    if (dem == 0) throw;
    
    this->num = num;
    this->dem = dem;
}

