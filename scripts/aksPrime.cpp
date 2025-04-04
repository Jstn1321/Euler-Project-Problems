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

bool aksPrimality(mpz_class n, long long longn){
    //Equation: (x-1)^p - (x^p - 1) 
    bool aksPrimality{true};

    std::list<mpz_class> halfCoeff = partialListCoeffOfPascal(n, longn);
    halfCoeff.pop_back();
    halfCoeff.pop_front();
    if (longn % 2 == 0){
        halfCoeff.push_back(2);
    }

    for (mpz_class i: halfCoeff){
        std::cout << i << "\n";
        if (i % n != 0){
            aksPrimality = false;
            break;
        }
    }

    return aksPrimality;
}

int main(){
    
    long long longn = 51736;
    mpz_class n = 51736;

    if (aksPrimality(n, longn) == 0){
        std::cout << n << " is not a prime";
    }
    else {
        std::cout << n << " is a prime";
    }
    
    return 0;
}