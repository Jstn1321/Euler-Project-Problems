#include <math.h>
#include <iostream>
#include <numeric>

int coprime(int a, int b){
    int coprime = 0;

    if (std::gcd(a, b) == 1){
        coprime = 1;
    }

    return coprime;
}

bool isPrime(int n){
    //Step 1: Determine if n is a perfect power, if so it is a composite
    double power{0.0};
    int r{0};
    bool isPrime = true;
    for (int i = 2; i <= log2(n); i++){
        power = pow(n, 1.0/i);
        if (((int)(power * 10)) % 10 == 0){
            isPrime = false;
            break;
        }
    }

    //Step 2: Determine the smallest multiplicative order of n, a, and if a and n are NOT coprime it is a composite

    if(isPrime == false){
        return isPrime;
    }

    while (true){
        r = 2;
        int k = pow(log2(n), 2);
        while (coprime(n, r) == 1){
            if ((int(pow(n, k)) % r) == 1){
                goto end_loops;
            }
            k++;
        }
        r++;
    }

    end_loops:
    if (coprime(r, n) != true){
        isPrime = false;
        return false;
    }

    return isPrime;
}

int main(){
    int n = 6;

    if (isPrime(n) == 0){
        std::cout << n << " is not a prime";
    }
    else {
        std::cout << n << " is most likely a prime";
    }
    return 0;
}