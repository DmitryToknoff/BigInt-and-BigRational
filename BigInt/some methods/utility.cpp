#include <string>
#include "BigInt.hpp"


BigInt abs(const BigInt &bi) {
    
    BigInt tmp = bi;
    
    tmp.sign = tmp.sign ? tmp.sign : !tmp.sign;
    
    return tmp;
}


std::string BigInt::get_string() {
    return sign ? num : '-' + num;
}


std::pair<std::string, std::string> get_larger_and_smaller(const std::string& num1, const std::string& num2) {
    std::string mx, mn;
    
    if (num1.size() > num2.size() || (num1.size() == num2.size() && num1 > num2)) {
        mx = num1;
        mn = num2;
    } else {
        mx = num2;
        mn = num1;
    }
    
    mx.insert(0, std::max(mx.size(), mn.size()) - mx.size(), '0');
    mn.insert(0, std::max(mx.size(), mn.size()) - mn.size(), '0');
    
    return {mx, mn};
    
}



std::string strip_leading_null(const std::string& s) {
    int i = 0;
    
    while (s[i] == '0')
        ++i;
    
    if (i == s.size()) {
        return "0";
    }
    
    return s.substr(i);
}


bool verify_degree_of_ten(const std::string& s) {
    if (s[0] != '1')
        return false;
    
    for (int i = 1; i < s.size(); ++i)
        if (s[i] != '0')
            return false;
    
    return true;
}


void add_back_null(std::string& s, int count_null) {
    s += std::string(count_null, '0');
}



std::pair<BigInt, BigInt> devide(const BigInt &divide, const BigInt &divisor) {
    return {};
}
