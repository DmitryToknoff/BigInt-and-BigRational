#include "BigInt.hpp"
#include "BigRat.hpp"


BigRational BigRational::operator*(const BigRational &br) const {
    BigRational res = *this;
    
    res.num *= br.num;
    res.dem *= br.dem;
    
    return res;
}


BigRational BigRational::operator * (const BigInt& bi) const {
    BigRational res = *this;
    
    res.num *= bi;
    
    return res;
}


BigRational BigRational::operator* (int x) const {
    return *this * BigInt(x);
}
