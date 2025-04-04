#include <math.h>
#include <iostream>
#include <random>
#include <ctime>
#include<windows.h>


bool fermatPrimality(long long n){

    bool isPrime = false;
    long long randNum = (rand() % (n-1)) + 2;

    for (int i = 0; i < 10; i++){
        if (pow(randNum, n-1) % n == 1){

        }
    }

    return isPrime;
}

int main(){
    for (int i = 0; i < 10; i++){
    std::cout << rand() << "\n";
    }
}