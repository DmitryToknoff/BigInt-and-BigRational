#ifndef BigInt_

#define BigInt_

#include <iostream>
#include <string>

#pragma GCC visibility push(default)
#pragma once

class BigInt
{
    std::string num;
    bool sign = true;
    
public:
    BigInt();
    BigInt(const BigInt& bi);
    BigInt(long long num);
    BigInt(char* s);
    
    std::string get_string();
    BigInt& operator= (const BigInt& bi);
    BigInt& operator= (char* num);
    BigInt& operator= (const long long num);
    BigInt& operator *= (const BigInt& bi);
    BigInt& operator /= (const BigInt& bi);
    BigInt& operator += (const BigInt& bi);
    BigInt& operator -= (const BigInt& bi);
    BigInt operator * (const BigInt& bi);
    BigInt operator / (const BigInt& bi);
    BigInt operator - (const BigInt& bi);
    BigInt operator + (const BigInt& bi);
    BigInt& operator - ();
    bool operator < (const BigInt& bi);
    bool operator > (const BigInt& bi);
    bool operator >= (const BigInt& bi);
    bool operator <= (const BigInt& bi);
    bool operator == (const BigInt& bi);
    bool operator != (const BigInt& bi);
    
    friend std::ostream& operator<< (std::ostream& os, const BigInt& bi);
    friend std::istream& operator>> (std::istream& is, const BigInt& bi);
    
    void ToString();
    
    
};

#pragma GCC visibility pop
#endif
