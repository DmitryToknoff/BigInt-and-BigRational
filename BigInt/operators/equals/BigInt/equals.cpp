#include "BigInt.hpp"
#include "string"


bool BigInt::operator== (const BigInt& bi) {
    return ((sign + bi.sign == 2) || (sign + bi.sign == 0)) && (bi.num == num);
}


bool BigInt::operator != (const BigInt& bi) {
    return !(*this == bi);
}

bool BigInt::operator< (const BigInt &bi) {
    if (!sign && bi.sign) return true;
        
    if ((sign && bi.sign) || (!sign && !bi.sign)) {
        
        if (sign) {
            if (num.size() < bi.num.size()) return true;
            else if (num.size() > bi.num.size()) return false;
            
            return num < bi.num;
        } else {
            if (num.size() > bi.num.size()) return true;
            else if (num.size() < bi.num.size()) return false;
            
            return num > bi.num;
        }
    }
    
    return false;
}


bool BigInt::operator > (const BigInt &bi) {
    return (!(*this < bi)) && (!(*this == bi));
}


bool BigInt::operator <= (const BigInt &bi) {
    return *this < bi || *this == bi;
}

bool BigInt::operator >= (const BigInt &bi) {
    return *this > bi || *this == bi;
}
