#include <iostream>
#include <math.h>
#include <random>
#include <gmpxx.h>

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    unsigned long long randNum{0};
    mpz_class exp{0};

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2,longn-2); // distribution in range [1, 6]

    randNum = dist6(rng);

    for (int i = 0; i < 10; i++){
        exp = pow(randNum, longn - 1);
        if (exp % n != 1){
            isPrime = false;
        }
    }

    return isPrime;
}

int main(){
    return 0;
}