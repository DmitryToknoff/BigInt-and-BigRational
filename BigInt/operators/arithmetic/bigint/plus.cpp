#include <string>
#include "BigInt.hpp"


BigInt& BigInt::operator += (const BigInt& bi) {
    
    if ((sign && bi.sign) || (!sign && !bi.sign)) {
        
        std::string mx_size = (num.size() <= bi.num.size() ? bi.num : num);
        std::string mn_size = (num.size() >= bi.num.size() ? bi.num : num);
        
        int cur = 0;
        
        for (int i = mn_size.size() - 1; i >= 0; --i) {
            int sum = (mx_size[i + mx_size.size() - mn_size.size()] - '0') + cur + (mn_size[i] - '0');
            
            if (sum >= 10) {
                cur = 1;
                sum %= 10;
                
            } else {
                cur = 0;
            }
            
            mx_size[i + mx_size.size() - mn_size.size()] = sum + '0';
        }
        
        if (cur == 1) {
            
            for (int i = mx_size.size() - mn_size.size() - 1; i >= 0; --i) {
                int sum = mx_size[i] - '0' + cur;
                
                if (sum >= 10) {
                    cur = 1;
                    sum %= 10;
                } else {
                    cur = 0;
                }
                
                mx_size[i] = sum + '0';
            }
            
            if (cur == 1) {
                num = '1' + mx_size;
            } else {
                num = mx_size;
            }
            
            
        } else {
            num = mx_size;
        }
    } else {
        BigInt tmp = bi;
        tmp.sign = !sign;
        
        *this -= tmp;
        
    }
    
    return *this;
    
}


BigInt BigInt::operator+ (const BigInt& bi) {
    BigInt tmp = *this;
    tmp += bi;
    
    return tmp;
}
