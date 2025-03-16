#include "BigInt.hpp"
#include <string>




BigInt& BigInt::operator -= (const BigInt& bi) {
    if (bi.num == "0") {return *this;}
    
    BigInt tmp = bi;
    tmp.sign = !sign;
    
    if ((sign && !bi.sign) || (!sign && bi.sign)) {
        
        *this += tmp;
        
        return *this;
    }
    
    if (bi.num == num) {sign = true; num = "0"; return *this;}
    
    bool flag = true;
    std::string mx_value, mn_value;
    
    if (abs(*this) > abs(tmp)) {
        mx_value = num;
        mn_value = tmp.num;
        
        if (!sign) {
            flag = false;
        }
        
    } else {
        mx_value = tmp.num;
        mn_value = num;
        
    }
    
    mn_value.insert(0, mx_value.size() - mn_value.size(), '0');
    std::string res = "";
    int cur;
    
    long long i, j;
    for (i = mx_value.size() - 1; i >= 0; --i) {
        cur = mx_value[i] - mn_value[i];
        
        if (cur < 0) {
            for (j = i -1; j >= 0; --j) {
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
        
        res = std::to_string(cur) + res;
    }
    
    i = 0;
    
    while (res[i] == '0') {
        ++i;
    }
    
    num = res.substr(i);
    
    
    return *this;
}




BigInt BigInt::operator- (const BigInt& bi) {
    BigInt tmp = *this;
    tmp -= bi;
    
    return tmp;
}
