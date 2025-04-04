#include <math.h>
#include <iostream>
#include <list>
#include <gmpxx.h>

mpz_class factorial(mpz_class n){
    if (n == 1){
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

mpz_class coeffOfPascal(mpz_class row, mpz_class col){
    // (row!)/((row-col)! * col!) 5040
    mpz_class currCoeff = (factorial(row))/((factorial(row-col)) * factorial(col));

    return currCoeff;
}

std::list<mpz_class> partialListCoeffOfPascal(mpz_class n, unsigned long long longn){
    
    std::list<mpz_class> coeff = {1, n};

    for (mpz_class col = 2; col <= (int)longn/2; col++){
        coeff.push_back(coeffOfPascal(n, col));
    }

    coeff.push_back(1);

    return coeff;
}

bool isPrime(mpz_class n, long long longn){
    //Equation: (x-1)^p - (x^p - 1) 
    bool isPrime{true};

    std::list<mpz_class> halfCoeff = partialListCoeffOfPascal(n, longn);
    halfCoeff.pop_back();
    halfCoeff.pop_front();
    if (longn % 2 == 0){
        halfCoeff.push_back(2);
    }

    for (mpz_class i: halfCoeff){
        //std::cout << i << "\n";
        if (i % n != 0){
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int main(){
    long long longi = 3;
    mpz_class i = 3;
    int primeCount = 1;
    while (true){
        if (isPrime(i,longi)){
            primeCount++;
            std::cout << longi << " " << primeCount << "\n";
            if (primeCount == 1001){
                break;
            }
        }
        i += 2;
        longi += 2;
    }
    
    std::cout << longi << "\n";

    return 0;
}