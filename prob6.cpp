#include <iostream>
#include <math.h>

int sumSqr(){
    int sum  = 0;
    for (int i = 1; i <= 100; i++){
        sum += pow(i, 2);
    }
    
    return sum;
}

int sqrSum(){
    int sum = 0;
    for (int i = 1; i <= 100; i++){
        sum += i;
    }
    sum = pow(sum, 2);
    return sum;
}

int main(){
    
    std::cout << sqrSum() - sumSqr();
    return 0;
}