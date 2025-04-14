#include <math.h>
#include <iostream>
#include <gmpxx.h>

bool isCoprime(unsigned long long a, unsigned long long b){
    
}

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = false;
    long long s{0};
    long long d{0};
    long long a{0};
    //Step 1 find 2^s * d
    for (s = 2; s < (int)log2(longn-1); s++){
        for (d = 1; pow(2, s) * d <= longn-1; d++){
            if (pow(2, s) * d == longn -1){
                goto end_loops;
            }
        }
    }
    end_loops:



    std::cout << s << " " << d << "\n";
    return isPrime;
}


int main(){
    probablePrime(221,221);
    return 0;
}