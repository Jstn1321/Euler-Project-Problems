#include <math.h>
#include <iostream>
#include <numeric>
#include <random>
#include <gmpxx.h>
#include <cstdlib>

bool isCoprime(unsigned long long a, unsigned long long b){
    bool isCoprime = false;
    if (std::gcd(a, b) == 1){
        isCoprime = true;
    }
    return isCoprime;
}

bool probablePrime(mpz_class n, unsigned long long longn){
    bool isPrime = true;
    unsigned long long s{0};
    unsigned long long d{0};
    unsigned long long a{0};
    unsigned long long test1{0};

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(2, longn-2);

    //Step 1 find 2^s * d
    while (true){
        for (s = 1; s < (int)log2(longn-1); s++){
            for (d = 1; pow(2, s) * d <= longn-1; d++){
                if (pow(2, s) * d == longn - 1){
                    if (std::floor(pow(2,s) * d) ==  )
                        goto end_loops;
                }
            }
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
    std::cout << probablePrime(561,561);
    return 0;
}