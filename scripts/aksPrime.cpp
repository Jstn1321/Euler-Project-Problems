#include <math.h>
#include <iostream>
#include <list>

std::list<unsigned long long> coeffOfPascal(unsigned long long n){

    std::list<unsigned long long> coeffHalf = {1, n};
    std::list<unsigned long long> coeffLastHalf;

    if (n == 2){
        coeffHalf = {1 , 2, 1};
    }

    if (n == 3){
        coeffHalf = {1 , 3, 3, 1};
    }

    if (n > 3){
        coeffHalf = {1, n};

        unsigned long long currCoeff = (n*(n-1))/2;
        coeffHalf.push_back(currCoeff);

        for (int i = 3; i <= ((int)(n)/2); i++){
            currCoeff *= (n-i+1)/(double)i;
            coeffHalf.push_back(currCoeff);
        }

        for (unsigned long long i : coeffHalf){
            coeffLastHalf.push_back(i);
        }
        if (n % 2 != 1){
            coeffLastHalf.pop_back();
        }
        coeffLastHalf.reverse();

        for (unsigned long long i: coeffLastHalf){
            coeffHalf.push_back(i);
        }
    }
    return coeffHalf;
}

bool isPrime(int n){
    //Equation: (x-1)^p - (x^p - 1) 
    bool isPrime{true};

    std::list<unsigned long long> coeffPrime;
    int numReplace{0};
    int last{0};
    int sum{};

    for (unsigned long long i : coeffOfPascal(n)){
        coeffPrime.push_back(i);
    }

    if (n % 2 == 0){
        last = 1;
    } else {
        last = -1;
    }

    numReplace = last + 1;
    coeffPrime.back() = numReplace;

    coeffPrime.pop_front();

    if (coeffPrime.back() == 0){
        coeffPrime.pop_back();
    }

    for (unsigned long long i: coeffPrime){
        if (i % n != 0){
            isPrime = false;
            break;
        }
    }

    for (unsigned long long i : coeffPrime){
        std::cout << i << "\n";
    }

    return isPrime;
}

int main(){
    unsigned long long n = 101;

    if (isPrime(n) == 0){
        std::cout << n << " is not a prime";
    }
    else {
        std::cout << n << " is a prime";
    }
    return 0;
}