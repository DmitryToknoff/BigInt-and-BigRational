#include <iostream>
#include <string>

#ifndef BigInt_
#define BigInt_


#pragma GCC visibility push(default)
#pragma once

class BigInt
{
    char* nums;
    size_t size = 0;
    bool sign = true;
    
    
    size_t get_size(const char* s);
    
public:
    BigInt();
    BigInt(const BigInt& bi);
    BigInt(long long num);
    BigInt(const char* s);
    
    ~BigInt();
    
    BigInt& operator= (const BigInt& bi);
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
