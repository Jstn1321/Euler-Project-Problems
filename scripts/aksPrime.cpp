#include <math.h>
#include <iostream>
#include <numeric>
#include <vector>

bool isPrime(int n){
    //Equation: (x-1)^p = (x^p - 1)
    bool isPrime = false;
    
    

    return isPrime;
}

int main(){
    int n = 31;

    if (isPrime(n) == 0){
        std::cout << n << " is not a prime";
    }
    else {
        std::cout << n << " is most likely a prime";
    }
    return 0;
}