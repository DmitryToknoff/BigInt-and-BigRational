#include "BigInt.hpp"
#include "BigRat.hpp"



BigRational BigRational::operator / (const BigRational& br) const {
    BigRational res;
    
    res.num = num * br.dem;
    res.dem = dem * br.num;
    
    
    return res;
}

BigRational BigRational::operator / (const BigInt& bi) const {
    BigRational res = *this;
    
    res.dem *= num;
    
    
    return res;
}


BigRational BigRational::operator / (int x) const {
    return *this / BigInt(x);
}

BigRational& BigRational::operator /= (const BigRational& br) {
    *this = *this / br;
    
    return *this;
}

BigRational& BigRational::operator /= (const BigInt& bi) {
    *this = *this / bi;
    
    return *this;
}


BigRational& BigRational::operator /= (int x) {
    *this = *this / x;
    
    return *this;
}


