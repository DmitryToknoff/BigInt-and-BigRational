#include <iostream>
#include <string>
#include "BigInt.hpp"


std::ostream& operator<< (std::ostream& os, const BigInt& bi) {
    if (!bi.sign) os << "-";
    
    for (int i = 0; i < bi.num.size(); ++i)
        os << bi.num[i];
    
    return os;
}
