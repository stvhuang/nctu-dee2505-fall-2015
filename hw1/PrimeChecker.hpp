/**
 * @filename PrimeChecker.hpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#ifndef _PRIMECHECKER_HPP_
#define _PRIMECHECKER_HPP_

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

const long SQRTLMAX = ( sqrt(LONG_MAX) + 1 ); //size of primeTable

class PRIMECHECKER {
private:
    vector<bool> isPrime;
    vector<long> primeTable;
    long int j, k;

public:
    PRIMECHECKER() : isPrime(SQRTLMAX) {
        isPrime[0] = true; // 0 is not a prime
        isPrime[1] = true; // 1 is not a prime

        for (long i(2); i < SQRTLMAX; ++i) { // Sieve of Eratosthenes
            if ( !isPrime[i] ) {
                for (long k( (SQRTLMAX - 1) / i ), j = i * k; k >= i; --k, j -= i) {
                    if ( !isPrime[k] ) {
                        isPrime[j] = true;
                    }
                }
            }
        }

        for (long i(0); i < SQRTLMAX; ++i) { // establish prime table
            if( !isPrime[i] ) { // isPrime[i] is a prime
                primeTable.push_back(i); // pushback prime to primeTable
            }
        }
    }

    long PrimeChecker(long, long);
};

#endif
