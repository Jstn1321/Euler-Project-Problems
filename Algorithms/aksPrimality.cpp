#include <cmath>
#include <iostream>
#include <gmpxx.h>
#include <list>

bool aksPrimality(mpz_class n, unsigned long long longn){
    //Step 1 determine if n is a perfect power if so return composite(false)

    bool isPrime = true;
    unsigned long long a{0};
    unsigned long long b{0};
    unsigned long long r{0};

    for (int i = 2; i <= log2(longn); i++){
        if((int)(pow(longn, 1.0/i) * 10) % 10 == 0){
            isPrime = false;
        }
    }

    if(!isPrime){
        std::cout << isPrime;
    }

    //Step 2, Find the smallest r such that ordr(n) > log2(n)^2, if n and r are not coprime, n is composite
    bool nextR = true;
    unsigned long long k{1};
    for (r = 2; nextR; r++){
        nextR = false;
        for (k = 1; !nextR && k <= (int)pow(log2(longn), 2); k++){
            nextR = ((int)pow(longn, k) % r == 1 || (int)pow(longn, k) % r == 0);
        }
    }
    r--;
    std::cout << r << "\n";
    return isPrime;
}

int main(){
    std::cout << aksPrimality(31,31);
}