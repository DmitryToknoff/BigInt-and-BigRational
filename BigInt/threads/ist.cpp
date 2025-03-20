#include <iostream>
#include <string>
#include "BigRat.hpp"
#include "BigInt.hpp"


std::istream& operator >> (std::istream& is, BigInt& bi)  {
    std::string s;
    is >> s;
    
    if (s[0] == '-') {
        bi.sign = false;
        bi.num = s.substr(1);
    } else {
        bi.num = s;
    }
    
    bi.num = strip_leading_null(bi.num);
    
    if (bi.num == "0") bi.sign = true;
    
    return is;
}


std::istream& operator >> (std::istream& is, BigRational& br) {
    std::string s;
    is >> s;
    
    bool flag = s[0] == '-';
    
    if (flag) {
        br.num = s.substr(1);
        br.num.set_sign(false);
    } else {
        br.num = s;
    }
    
    is >> s;
    
    br.dem = s;
    
    return is;
}

