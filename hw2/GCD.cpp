/**
 * @filename GCD.cpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#include "GCD.hpp"

void GCD::simplify(long long* a) {
    int deg( finddeg(a) );

    long long gcd( findgcd(a, deg) );
    if (a[ finddeg(a) ] < 0) {
        gcd = (-1) * myabs(gcd);
    } else {
        gcd = abs(gcd);
    }

    for (int i(0); i <= deg; ++i) {
        if (gcd) {
            a[i] = (a[i] / gcd);
        }
    }
}

bool GCD::check_all_zero(long long* a) {
    for (int i( finddeg(a) ); i >= 0; --i) {
        if (a[i]) {
            return false;
        }
    }
    return true;
}

int GCD::finddeg(long long* arr) {
    for (int i(ARRAY_MAX-1); i >= 0; --i) {
        if (arr[i]) {
            return i;
        }
    }
    return 0;
}

long long GCD::findgcd(long long *a, int right) {
    int i(right);

    if (right == 1) {
        return gcd( a[0], a[i] );
    } else if (right == 0) {
        return a[0];
    } else if (a[i - 1] == 0) {
        return gcd( findgcd(a, i-2), a[i] );
    } else {
        return gcd( findgcd(a, i-1), a[i] );
    }
}

long long GCD::gcd(long long a, long long b) {
    long long c;
    while (a != 0) {
        c = a;
        if ( a ) {
            a = b % a;
        }
        b = c;
    }
    return b;
}

long long GCD::myabs(long long a) {
    if (a >= 0) {
        return a;
    } else {
        return ( a * (-1) );
    }
}

long long * GCD::FindGCD(long long *in1, long long *in2) {
    while (1) {
        simplify(in2);
        simplify(in1);

        if ( finddeg(in1) > finddeg(in2) ) {
            in1 = mod(in1, in2);

            if ( check_all_zero(in1) ) {
                simplify(in2);
                return in2;
            }
        } else if ( finddeg(in2) >= finddeg(in1) ) {
            in2 = mod(in2, in1);
            if ( check_all_zero(in2) ) {
                simplify(in1);
                return in1;
            }
        }
    }
}

long long * GCD::mod(long long* a, long long* b) {
    int ddeg( finddeg(a) - finddeg(b) );
    long long ablcm( myabs( a[ finddeg(a) ] ) * myabs( b[ finddeg(b) ] ) / gcd( a[ finddeg(a) ], b[ finddeg(b) ] ) );
    long long da( ablcm / a[ finddeg(a) ] ), db( ablcm / b[ finddeg(b) ] );

    int i(0);
    for(i = finddeg(a); (i - ddeg) >= 0; --i) {
            a[i] = a[i] * da - b[i - ddeg] * db;
    }

    for (; i >= 0; --i) {
        a[i] = da * a[i];
    }

    return a;
}
