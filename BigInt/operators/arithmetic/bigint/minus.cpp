#include "BigInt.hpp"
#include <string>
#include <iostream>




BigInt BigInt::operator - (const BigInt& bi) const {
    if (sign && !bi.sign) {
        BigInt tmp = bi;
        tmp.sign = true;
        
        return *this + tmp;
    }
    
    if (!this->sign && bi.sign) {
        BigInt tmp = *this;
        tmp.sign = true;
        
        return - (tmp + bi);
    }
    
    BigInt res;
    
    std::string mx_value, mn_value;
    
    if (abs(*this) > abs(bi)) {
        mx_value = num;
        mn_value = bi.num;
        
        if (!sign) {
            res.sign = false;
        }
        
    } else {
        mx_value = bi.num;
        mn_value = num;
        
        if (bi.sign)
            res.sign = false;
        
    }
    
    mx_value.insert(0, (std::max(mx_value.size(), mn_value.size()) - mx_value.size()), '0');
    mn_value.insert(0, (std::max(mx_value.size(), mn_value.size()) - mn_value.size()), '0');
    
    res.num = "";
    
    int cur;
    int i, j;
    
    
    for (i = mx_value.size() - 1; i >= 0; --i) {
        cur = mx_value[i] - mn_value[i];
        
        if (cur < 0) {
            for (j = i - 1; j >= 0; --j) {
                if (mx_value[j] != '0') {
                    --mx_value[j];
                    break;
                }
            }
            
            ++j;
            
            while (j != i) {
                mx_value[j] = '9';
                ++j;
            }
            
            cur += 10;
        }
        
        res.num = std::to_string(cur) + res.num;
    }
    
    res.num = strip_leading_null(res.num);
    
    if (res.num == "0") {
        res.sign = true;
    }
    
    return res;

}


BigInt& BigInt::operator -= (const BigInt& bi) {
    BigInt tmp = *this - bi;
    num = tmp.num;
    sign = tmp.sign;
    
    return *this;
}
