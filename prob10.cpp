#include <iostream>
#include <math.h>
#include <random>
#include <gmpxx.h>
#include <string>

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    unsigned long long randNum{0};
    mpz_class exp{0};

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2,longn-2);

    randNum = dist6(rng);

    for (int i = 0; i < 10; i++){
        randNum = dist6(rng);
        exp = pow(randNum, longn - 1);
        if (exp % n != 1){
            isPrime = false;
        }
    }

    return isPrime;
}

int main(){
    unsigned long long sum{1};
    mpz_class mpzi{3};

    for (unsigned long long i = 3; i < 2000000; i+=2){
        if (probablePrime(mpzi,i) == 1){
            sum += i;
        }
        mpzi++;
    }

    std::string sumstr = std::stoi(sum);
    return 0;
}