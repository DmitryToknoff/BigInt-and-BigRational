#include "BigInt.hpp"
#include <string>
#include <cmath>


const long long FLOOR_SQRT_LLONG_MAX = 3037000499;

BigInt BigInt::operator* (const BigInt& bi) const {
    if (bi.num == "0" || num == "0") {
        return BigInt(0ll);
    }
    
    if ((*this) == 1) {
        return bi;
    }
    
    if (bi == 1) {
        return *this;
    }
    
    BigInt res;
    
    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX && abs(bi) <= FLOOR_SQRT_LLONG_MAX) {
        res = std::stoll(this->num) * std::stoll(bi.num);
    } else if (verify_degree_of_ten(this->num)) {
        res.num = bi.num;
        res.num.append(this->num.begin() + 1, this->num.end());
    } else if (verify_degree_of_ten(bi.num)) {
        res.num = num;
        res.num.append(bi.num.begin() + 1, bi.num.end());
    } else {
        
        std::string mx_value, mn_value;
        auto ttt = get_larger_and_smaller(this->num, bi.num);
        
        mx_value = ttt.first;
        mn_value = ttt.second;
        
        size_t hsz = mx_value.size() / 2;
        auto hszc = (size_t) (ceil(mx_value.size() / 2.0));
        
        BigInt hight1, low1;
        
        hight1 = mx_value.substr(0, hsz);
        low1 = mx_value.substr(hsz);
        
        
        BigInt hight2, low2;
        
        hight2 = mn_value.substr(0, hsz);
        low2 = mn_value.substr(hsz);
        
        hight1.num = strip_leading_null(hight1.num);
        low1.num = strip_leading_null(low1.num);
        hight2.num = strip_leading_null(hight2.num);
        low2.num = strip_leading_null(low2.num);
        
        
        BigInt prod_hight, prod_mid, prod_low;
        
        prod_hight = hight1 * hight2;
        prod_low = low1 * low2;
        prod_mid = (hight1 + low1) * (hight2 + low2) - prod_hight - prod_low;
        
        add_back_null(prod_hight.num, 2 * hszc);
        add_back_null(prod_mid.num, hszc);
        
        prod_low = strip_leading_null(prod_low.num);
        prod_mid = strip_leading_null(prod_mid.num);
        prod_hight = strip_leading_null(prod_hight.num);
        
        res = prod_hight + prod_mid + prod_low;
    }
    
    res.num = strip_leading_null(res.num);
    
    if  (this->sign == bi.sign) {
        res.sign = true;
    } else {
        res.sign = false;
    }
    
    return res;
}

BigInt& BigInt::operator *= (const BigInt& bi) {
    BigInt tmp = *this * bi;
    
    num = tmp.num;
    sign = tmp.sign;
    
    return *this;
}


