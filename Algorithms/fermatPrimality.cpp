#include <iostream>
#include <math.h>
#include <random>
#include <gmpxx.h>
#include <cstdlib>
using namespace std;

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    unsigned long long randNum{0};
    mpz_class exp{0};

    srand((unsigned) time(NULL));


	randNum = (rand() * longn -1) + 2;
    exp = pow(randNum, longn-1);
    
    for (int i = 0; i < 10; i++){
        randNum = rand();
        exp = pow(randNum, longn - 1);
        cout << exp << "\n";
        if (exp % n != 1){
            isPrime = false;
        }
    }

    return isPrime;
}

int main(){
    cout << probablePrime(7, 7);
    return 0;
}