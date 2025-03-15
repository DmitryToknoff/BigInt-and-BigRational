#include <iostream>
#include <string>

#ifndef BigInt_
#define BigInt_


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
    BigInt(const std::string& s);
    
    ~BigInt();
    
    BigInt& operator= (const BigInt& bi);
    BigInt& operator= (const std::string num);
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
    bool operator <= (const BigInt& bi);
    bool operator == (const BigInt& bi);
    
    friend std::ostream& operator<< (std::ostream& os, const BigInt& bi);
    friend std::istream& operator>> (std::istream& is, const BigInt& bi);
    
    void ToString();
    
    
};

#pragma GCC visibility pop
#endif
