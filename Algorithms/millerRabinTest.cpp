#include <math.h>
#include <iostream>
#include <numeric>
#include <random>
#include <gmpxx.h>
#include <cstdlib>
#include <list>

bool isCoprime(unsigned long long a, unsigned long long b){
    bool isCoprime = false;
    if (std::gcd(a, b) == 1){
        isCoprime = true;
    }
    return isCoprime;
}

mpz_class modExp(mpz_class base, mpz_class exp, mpz_class mod){
    mpz_class result{1};
    for (int i = 0; i < exp; i++){
        result *= base;
    }
    result %= mod;
    return result;
}

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    float powResult{0};
    unsigned long long prevS{0};
    unsigned long long prevD{0};
    unsigned long long s{0};
    unsigned long long d{0};
    unsigned long long a{0};
    unsigned long long test1{0};
    std::list<int> testA {0};
    mpz_class temp{0};

    if (n < 2047){
        testA = {2};
    }
    else if (longn < 1373653){
        testA = {2, 3};
    }
    else if (longn < 25326001){
        testA = {2, 3, 5};
    }
    else if (longn < 118670087467){
        testA = {2, 3, 5, 7};
    }
    else if (longn < 2152302898747){
        testA = {2, 3, 5, 7, 11};
    }
    else if (longn < 3474749660383){
        testA = {2, 3, 5, 7, 11, 13};
    }
    else if (longn < 341550071728321){
        testA = {2, 3, 5, 7, 11, 13, 17};
    }
    else {
        testA = {2, 3, 5, 7, 11, 13, 17};
    }

    //Step 1 find 2^s * d

    for (s = 1; s < (int)log2(longn-1); s++){
        powResult = (longn -1)/ pow(2, s);
        std::cout << s << " " << d << " " << powResult << "\n";
        if (std::floor(powResult) == powResult){
            prevS = s;
            prevD = powResult;
        }
        else {
            s = prevS;
            d = prevD;
            goto end_loops;
        }
    }

    end_loops:
    
    std::cout << s << " " << d << "\n";
    return isPrime;
}


int main(){
    //probablePrime(221,221);
    std::cout << probablePrime(221,221) << std::endl;
    return 0;
}