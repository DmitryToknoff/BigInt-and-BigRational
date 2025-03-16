#include "BigInt.hpp"
#include <string>


BigInt& BigInt::operator *= (const BigInt& bi) {
    return *this;
}



BigInt BigInt::operator*(const BigInt &bi) {
    return BigInt();
}
