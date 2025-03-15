#include "BigInt.hpp"
#include "string"


std::string BigInt::get_string() {
    return sign ? num : '-' + num;
}
