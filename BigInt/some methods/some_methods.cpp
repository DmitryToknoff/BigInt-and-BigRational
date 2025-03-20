#include "BigInt.hpp"
#include <string>
#include "BigRat.hpp"



void BigRational::reduce() {
    BigInt bg = gcd(abs(num), abs(dem));
    
    num /= bg;
    dem /= bg;
    
    if (dem < 0) {
        num = -num;
        dem = -dem;
    }
}

bool BigInt::get_sign() const {
    return sign;
}

int BigRational::sum_sign() const {
    return num.get_sign() + dem.get_sign();
}

void BigInt::set_sign(bool flag) {
    sign = flag;
}

std::string BigRational::Decimal(int precision) const {
    if (dem == 0) throw std::logic_error("bad dem");
    
    BigInt tmp = num / dem, rem = num % dem;
    
    std::string decimal = tmp.get_string() + ".";
    
    for (int i = 0; i < precision; ++i) {
        rem *= BigInt(10);
        BigInt d = rem / dem;
        decimal += d.get_string();
        rem %= dem;
        
        if (rem == 0) break;
    }
    
    return decimal;
}
