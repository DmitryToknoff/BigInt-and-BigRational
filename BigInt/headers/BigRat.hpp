#ifndef BigRational_
#define BigRational_

#include <iostream>
#include <string>
#include <cmath>

#pragma GCC visibility push(default)
#pragma once

#include "BigInt.hpp"

class BigRational {
    BigInt num;
    BigInt dem;
    
    
    int sum_sign() const;
    
public:
    BigRational();
    BigRational(const BigInt& bi);
    BigRational(const BigRational& br);
    BigRational(int num);
    BigRational(long long num);
    BigRational(const BigInt& num, const BigInt& dem);
    
    BigRational& operator = (const BigRational& br);
    BigRational& operator = (const BigInt& bi);
    BigRational& operator = (int x);
    
    BigRational operator + (const BigRational& br) const;
    BigRational operator + (const BigInt& bi) const;
    BigRational operator + (int x) const;
    
    BigRational operator - (const BigRational& br) const;
    BigRational operator - (const BigInt& bi) const;
    BigRational operator - (int x) const;
    
    BigRational operator * (const BigRational& br) const;
    BigRational operator * (const BigInt & bi) const;
    BigRational operator * (int x) const;
    
    BigRational operator / (const BigRational& br) const;
    BigRational operator / (const BigInt& bi) const;
    BigRational operator / (int x) const;
    
    BigRational& operator += (const BigRational& br);
    BigRational& operator += (const BigInt& bi);
    BigRational& operator += (int x);
    
    BigRational& operator -= (const BigRational& br);
    BigRational& operator -= (const BigInt& br);
    BigRational& operator -= (int x);
    
    BigRational& operator *= (const BigRational& br);
    BigRational& operator *= (const BigInt& br);
    BigRational& operator *= (int x);
    
    BigRational& operator /= (const BigRational& br);
    BigRational& operator /= (const BigInt& br);
    BigRational& operator /= (int x);
    
    bool operator < (const BigRational& br) const;
    bool operator < (int x);
    bool operator > (const BigRational& br) const;
    bool operator > (int x);
    bool operator >= (const BigRational& br) const;
    bool operator >= (int x);
    bool operator <= (const BigRational& br) const;
    bool operator <= (int x);
    bool operator == (const BigRational& br) const;
    bool operator == (int x);
    bool operator != (const BigRational& br) const;
    bool operator != (int x);
    
    BigRational operator + ();
    BigRational operator - ();
    
    BigRational& operator++ ();
    BigRational& operator-- ();
    BigRational operator++ (int);
    BigRational operator-- (int);
    
    
    std::string Decimal(int precision = 10) const;
    
    friend std::ostream& operator<< (std::ostream& os, const BigRational& br);
    friend std::istream& operator>> (std::istream& is, BigRational& br);
    
    void reduce();
};

template<typename T>
T gcd(const T& a, const T& b) {
    if (b == 0)
        return a;
    
    return gcd(b, a%b);
}


#pragma GCC visibility pop
#endif
