#include "BigRat.hpp"
#include "BigInt.hpp"



bool BigRational::operator == (const BigRational& br) const {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    if ((((tmp1).sum_sign() == 2 || (tmp1).sum_sign() == 0) && ((tmp).sum_sign() == 2 || (tmp).sum_sign() == 0)) || tmp.sum_sign() == (tmp1).sum_sign()) {
        if (abs(tmp1.num) == abs(tmp.num) && abs(tmp1.dem) == abs(tmp.dem)) {
            return true;
        }
    }
    
    return false;
}



bool BigRational::operator != (const BigRational& br) const  {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return !(tmp1 == tmp);
}


bool BigRational::operator < (const BigRational& br) const {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    if ((tmp1).sum_sign() == 1 && (tmp.sum_sign() == 2 || tmp.sum_sign() == 0)) {
        return true;
    } else if ((((tmp1).sum_sign() == 2 || (tmp1).sum_sign() == 0) && ((tmp).sum_sign() == 2 || (tmp).sum_sign() == 0))) {
        BigRational m = tmp1;
        BigRational tmp2 = tmp;
        
        m.num *= tmp2.dem;
        tmp2.num *= m.dem;
        
        m.num = abs(m.num);
        tmp2.num = abs(tmp2.num);
        
        if (m.num < tmp2.num) return true;
    }
    
    return false;
}


bool BigRational::operator > (const BigRational& br) const {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return (!(tmp1 < tmp)) && (!(tmp1 == tmp));
}


bool BigRational::operator <= (const BigRational &br) const {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 < tmp || tmp1 == tmp;
}

bool BigRational::operator >= (const BigRational &br) const {
    BigRational tmp = br, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 > tmp || tmp1 == tmp;
}


bool BigRational::operator < (int x)  {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 < tmp;
}

bool BigRational::operator > (int x) {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 > tmp;
    
}

bool BigRational::operator <= (int x)  {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 <= tmp;
}

bool BigRational::operator >= (int x)  {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 >= tmp;
}


bool BigRational::operator == (int x)  {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 == tmp;
}

bool BigRational::operator != (int x)  {
    BigRational tmp = x, tmp1 = *this;
    tmp1.reduce();
    tmp.reduce();
    
    return tmp1 != tmp;
}
