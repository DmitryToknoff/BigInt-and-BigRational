#include <iostream>
#include <string>
#include "BigInt.hpp"
#include "BigRat.hpp"


std::ostream& operator<< (std::ostream& os, const BigInt& bi) {
    if (!bi.sign) os << "-";
    
    for (int i = 0; i < bi.num.size(); ++i)
        os << bi.num[i];
    
    return os;
}


std::ostream& operator<< (std::ostream& os, const BigRational& br) {
    os << br.Decimal();
    return os;
    
}
