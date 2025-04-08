#include <iostream>
#include <cmath>

int main(){
    //a^2 + b^2 = c^2
    //a<b<c
    // a + b + c = 1000
    int a{0};
    int b{0};
    double c{0};

    for (a; a < 998; a++){
        for (b = a+1; b < 998; b++){
            c = sqrt(pow(a, 2) + pow(b, 2));
            ///std::cout << a << " " << b << " " << c << "\n";
            if (c - (int)c == 0.0 && c < 999){
                std::cout << c << "\n";
                if(a + b + (int)c == 1000){
                    break;
                }
            }
        }
    }

    std::cout << "a: " << a << " " << "b: " << b;
    return 0;
}