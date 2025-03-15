//
//  BigInt.cpp
//  BigInt
//
//  Created by Дмитрий Токнов on 16.03.2025.
//

#include <iostream>
#include "BigInt.hpp"
#include "BigIntPriv.hpp"

void BigInt::HelloWorld(const char * s)
{
    BigIntPriv *theObj = new BigIntPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void BigIntPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

