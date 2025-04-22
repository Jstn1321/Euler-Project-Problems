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
    std::list<int> testA {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, longn-2);

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
    for (int i = 0; i < 2; i++){
        a = distrib(gen);
        test1 = pow(a, d);
        test1 %= longn;
        if(test1 != 1){
            isPrime = false;
            break;
        }
        
    }

    std::cout << s << " " << d << "\n";
    return isPrime;
}


int main(){
    //probablePrime(221,221);
    std::cout << probablePrime(221,221);
    return 0;
}