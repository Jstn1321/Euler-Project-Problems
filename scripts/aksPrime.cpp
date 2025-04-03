#include <math.h>
#include <iostream>

bool isPrime(int n){
    //Step 1: Determine if n is a perfect power, if so it is a composite
    double power{0};
    bool isPrime = true;
    for (int i = 2; i < log2(n); i++){
        power =  pow(n, 1.0/i);
        if ((int)(power * 10) % 10 != 0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main(){
    std::cout << isPrime(6);
    return 0;
}