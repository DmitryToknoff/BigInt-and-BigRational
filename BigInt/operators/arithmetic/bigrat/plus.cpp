#include "BigRat.hpp"
#include <iostream>
#include "BigInt.hpp"

// dopil reduce

BigRational BigRational::operator + (const BigInt& bi) const {
    BigRational res = *this;
    res.num += bi;
    
    return res;
}


BigRational BigRational::operator + (int x) const {
    BigRational res = *this;
    res.num += x;
    
    return res;
}



BigRational& BigRational::operator += (const BigInt& bi) {
    *this = *this + bi;
    
    return *this;
}

BigRational& BigRational::operator += (int x) {
    *this = *this + x;
    
    return *this;
}


BigRational BigRational::operator+ (const BigRational& br) const {
    BigInt new_num = (num * br.dem) + (br.num * dem);
    BigInt new_dem = br.dem * dem;
    
    
    return BigRational(new_num, new_dem);
    
}


BigRational& BigRational::operator += (const BigRational& br) {
    *this = *this + br;
    
    return *this;
}


BigRational operator + (const BigRational& br, const BigInt& bi) {
    return br + BigRational(bi);
}


BigRational operator + (const BigRational& br, int x) {
    return br + BigRational(x);
}
