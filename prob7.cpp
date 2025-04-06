#include <gmpxx.h>
#include <iostream>
#include <math.h>

bool isMaybePrime(unsigned long long n){
    mpz_t bigint;
    mpz_init_set_si(bigint, n);
    bool ret = mpz_probab_prime_p(bigint, 25) > 0;
    mpz_clear(bigint);
    return ret;
}

int main(){
    int primeCount{1};
    unsigned long long n{3};
    while(true){
        if (primeCount == 10001){
            break;
        }
        if (isMaybePrime(n)){
            primeCount++;
        }
        n += 2;
    }
    n -= 2;
    std::cout << n;
}