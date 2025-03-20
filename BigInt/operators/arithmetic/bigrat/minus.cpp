#include <string>
#include "BigRat.hpp"
#include "BigInt.hpp"



BigRational BigRational::operator - (int x) const {
    BigRational res = *this;
    
    res.num -= (BigInt(x) * res.dem);
    
    return res;
}


BigRational BigRational::operator - (const BigInt& bi) const {
    BigRational res = *this;
    
    res.num -= (bi * res.dem);
    
    return res;
}


BigRational BigRational::operator - (const BigRational& br) const {
    BigRational res = *this;
    
    
    res.dem = dem * br.dem;
    res.num = num * br.dem - br.num * dem;
    
    
    return res;
}





BigRational& BigRational::operator -= (int x) {
    *this = *this - x;
    
    return *this;
}


BigRational& BigRational::operator -= (const BigInt& bi) {
    *this = *this - bi;
    
    return *this;
}


BigRational& BigRational::operator -= (const BigRational& br) {
    *this = *this - br;
    
    
    return *this;
}
