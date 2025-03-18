#include <string>
#include "BigInt.hpp"
#include <cmath>


BigInt BigInt::operator + (const BigInt& bi) const {
    if (sign && !bi.sign) {
        BigInt tmp = bi;
        tmp.sign = true;
        
        return *this - tmp;
        
    } else if (!sign && bi.sign) {
        BigInt tmp = *this;
        tmp.sign = true;
        
        return -(tmp - bi);
    }
    
    
    std::string mx_value, mn_value;
    auto ttt = get_larger_and_smaller(num, bi.num);
    
    mx_value = ttt.first;
    mn_value = ttt.second;
    
    BigInt res;
    res.num = "";
    
    int cur = 0, sum;
    
    for (int i = mx_value.size() - 1; i >= 0; --i) {
        sum = mx_value[i] - '0' + mn_value[i] - '0' + cur;
        
        res.num = std::to_string(sum%10) + res.num;
        cur /= 10;
    }
    
    if (cur) {
        res.num = std::to_string(cur) + res.num;
    }
    
    if (!this->sign && res.num != "0")
        res.sign = false;
    
    return res;
}


BigInt& BigInt::operator += (const BigInt& bi) {
    BigInt tmp = *this + bi;
    num = tmp.num;
    sign = tmp.sign;
    
    return *this;
}

