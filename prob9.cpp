#include <iostream>
#include <cmath>
#include <cstdlib>

int main(){
    //a^2 + b^2 = c^2
    //a<b<c
    // a + b + c = 1000
    double a{1};
    double b{1};
    double c{0};
    long long result;

    for(a; a < 998; a++){
        for (b = a+1; b < 998; b++){
            c = sqrt(pow(a, 2) + pow(b, 2));
            ///std::cout << a << " " << b << " " << c << "\n";
            if (c - (int)c == 0.0 && c < 999){
                if(a + b + (int)c == 1000){
                    goto end_loops;
                }
            }
        }
    }

    end_loops:
    result = a * b * c;
    std::cout << result;
    return 0;
}