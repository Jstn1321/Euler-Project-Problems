#include <iostream>
#include <numeric>

int coprime(int a, int b){
    int coprime = 0;

    if (std::gcd(a, b) == 1){
        coprime = 1;
    }

    return coprime;
}