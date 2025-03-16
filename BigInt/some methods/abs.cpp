#include "BigInt.hpp"



BigInt abs(const BigInt &bi) {
    
    BigInt tmp = bi;
    
    tmp.sign = tmp.sign ? tmp.sign : !tmp.sign;
    
    return tmp;
}
