/**
 * @filename PrimeChecker.cpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#include "PrimeChecker.hpp"

long PRIMECHECKER::PrimeChecker(long a, long b) {
    bool prime_or_not(true);
    long num_prime(0);
    const long devideBound(sqrt(b) + 1);

    if (a % 2) { // a is an odd
        for (int i(a); i <= b; i += 2) {
            prime_or_not = true;
            for (int j(0); primeTable[j] <= devideBound; ++j) {
                if ( !( i % primeTable[j] ) ) {
                    prime_or_not = false;
                    break;
                }
            }
            if (prime_or_not) {
                ++num_prime;
            }
        }
    } else { // a is an even
        for (int i(a + 1); i <= b; i += 2) {
            prime_or_not = true;
            for (int j(0); primeTable[j] <= devideBound; ++j) {
                if ( !( i % primeTable[j] ) ) {
                    prime_or_not = false;
                    break;
                }
            }
            if(prime_or_not) {
                ++num_prime;
            }
        }
    }

    return num_prime;
}
