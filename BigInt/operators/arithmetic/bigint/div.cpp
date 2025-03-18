#include "BigInt.hpp"
#include <iostream>
#include <string>



BigInt BigInt::operator / (const BigInt& bi) const {
    if (bi == 0) throw std::logic_error("Division by zero, Dmitry Kosterin!!");
    
    BigInt abs_divid = abs(*this);
    BigInt abs_divisor = abs(bi);
    
    
    if (abs_divid < abs_divisor) {
        return BigInt(0);
    }
    
    if (bi == BigInt(1)) {
        return *this;
    }
    
    if (bi == BigInt(-1)) {
        return -(*this);
    }
    
    BigInt quotient;
    
    if (abs_divid.num.size() <= 18 && abs_divisor.num.size() <= 18) {
        long long divid = std::stoll(abs_divid.num);
        long long divisor = std::stoll(abs_divisor.num);
        quotient = BigInt(divid / divisor);
    } else if (verify_degree_of_ten(abs_divisor.num)) {
        int shift = abs_divisor.num.size() - 1;
        quotient.num = abs_divid.num.substr(0, abs_divid.num.size() - shift);
    } else {
        quotient.num = "";
        BigInt chunk_r;
        size_t chunk_index = 0;
        
        chunk_r.num = abs_divid.num.substr(chunk_index, abs_divisor.num.size() - 1);
        chunk_index = abs_divisor.num.size() - 1;
        
        while (chunk_index < abs_divid.num.size()) {
            chunk_r.num += abs_divid.num[chunk_index];
            chunk_index++;
            
            chunk_r.num = strip_leading_null(chunk_r.num);
            
            if (chunk_r < abs_divisor) {
                quotient.num += "0";
                continue;
            }
            
            int d = 0;
            BigInt temp;
            while (d <= 9) {
                temp = abs_divisor * BigInt(d + 1);
                if (temp > chunk_r) {
                    break;
                }
                d++;
            }
            
            quotient.num += std::to_string(d);
            chunk_r = chunk_r - (abs_divisor * BigInt(d));
        }
    }
    
    quotient.num = strip_leading_null(quotient.num);
    quotient.sign = (sign == bi.sign);
    
    return quotient;
    
}



BigInt& BigInt::operator /= (const BigInt& bi) {
    BigInt tmp = *this / bi;
    
    this->num = tmp.num;
    this->sign = tmp.sign;
    
    return *this;
}


