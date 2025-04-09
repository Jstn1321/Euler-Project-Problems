#include <gmpxx.h>
#include <iostream>
#include <math.h>

#include <iostream>
#include <math.h>
#include <random>
#include <gmpxx.h>
#include <cstdlib>

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    mpz_class randNum{0};
    mpz_class exp{0};
    mpz_class mod{0};

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, longn-2);

    for (int i = 0; i < 3; i++){
        randNum = distrib(gen);
        //std::cout << randNum << "\n";
        //exp = pow(randNum, longn - 1);
        mpz_pow_ui(exp.get_mpz_t(), randNum.get_mpz_t(), longn-1);
        //std::cout << exp << "\n";
        mod = exp % n;
        //std::cout << mod << "\n";
        if (mod != 1){
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int main(){
    int primeCount{2};
    unsigned long long longn{5};
    mpz_class n{5};
    while(true){
        std::cout << n << " " << longn << " " << primeCount << "\n";
        if (primeCount == 3){
            break;
        }
        if (probablePrime(n, longn)){
            primeCount++;
        }
        n += 2;
        longn += 2;
    }
    n-=2;
    longn-=2;
    std::cout << n;
    return 0;
}