#include <math.h>
#include <iostream>
#include <numeric>
#include <vector>

bool isPrime(int n){
    //Equation: (x-1)^p - (x^p - 1) 
    // When p is a odd number it ends with -1 and vise versa
    bool isPrime = false;

    return isPrime;
}

int main(){
    int primeCount = 0;
    long long i = 2;
    while (true){
        std::cout << i << " " << primeCount << "\n";
        if (primeCount == 1001){
            break;
        }
        if (isPrime(i)){
            primeCount++;
        }
        i++;
    }

    std::cout << i;
    return 0;
}