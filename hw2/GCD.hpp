/**
 * @filename GDC.hpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#ifndef _GCD_HPP_
#define _GCD_HPP_

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>

#define ARRAY_MAX 1000

using namespace std;

class GCD {
private:

public:
    GCD(){}
    ~GCD(){}
    void simplify(long long* a);
    bool check_all_zero(long long* a);
    int finddeg(long long* arr);
    long long findgcd(long long *a, int right);
    long long gcd(long long a, long long b);
    long long myabs(long long a);
    long long * FindGCD(long long *in1, long long *in2);
    long long * mod(long long* a, long long* b);
};

#endif
