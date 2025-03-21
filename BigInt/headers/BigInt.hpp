#ifndef BigInt_

#define BigInt_

#include <iostream>
#include <string>

#pragma GCC visibility push(default)
#pragma once

class BigInt {
    std::string num;
    bool sign = true;
    
public:
    BigInt();
    BigInt(const BigInt& bi);
    BigInt(int num);
    BigInt(const std::string&);
    BigInt(long long num);
    BigInt(char* s);
    
    std::string get_string();
    
    BigInt& operator= (const BigInt& bi);
    BigInt& operator= (char* num);
    BigInt& operator= (const long long num);
    
    BigInt& operator *= (const BigInt& bi);
    BigInt& operator /= (const BigInt& bi);
    BigInt& operator += (const BigInt& bi);
    BigInt& operator %= (const BigInt& bi);
    BigInt& operator -= (const BigInt& bi);
    BigInt operator * (const BigInt& bi) const;
    BigInt operator / (const BigInt& bi) const;
    BigInt operator % (const BigInt& bi) const;
    BigInt operator - (const BigInt& bi) const;
    BigInt operator + (const BigInt& bi) const;
    
    BigInt operator + ();
    BigInt operator - () const;
    
    BigInt& operator++ ();
    BigInt& operator-- ();
    BigInt operator++ (int);
    BigInt operator-- (int);
    
    bool operator < (const BigInt& bi) const;
    bool operator < (long long x) const;
    bool operator > (const BigInt& bi) const;
    bool operator > (long long x) const;
    bool operator >= (const BigInt& bi) const;
    bool operator >= (long long x) const;
    bool operator <= (const BigInt& bi) const;
    bool operator <= (long long x) const;
    bool operator == (const BigInt& bi) const;
    bool operator == (long long x) const;
    bool operator != (const BigInt& bi) const;
    bool operator != (long long x) const;
    
    friend std::ostream& operator<< (std::ostream& os, const BigInt& bi);
    friend std::istream& operator>> (std::istream& is, BigInt& bi);
    
    
    void ToString();
    friend BigInt abs(const BigInt& bi);
    bool get_sign() const;
    void set_sign(bool flag);
};


std::string strip_leading_null(const std::string& s);
void add_back_null(std::string& s, int count_null);
bool verify_degree_of_ten(const std::string& s);
std::pair<std::string, std::string> get_larger_and_smaller(const std::string& num1, const std::string& num2);

#pragma GCC visibility pop
#endif
