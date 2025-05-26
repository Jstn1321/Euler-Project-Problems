#include <cmath>
#include <iostream>

int triangleNumGen(int num)
{
    int triNum{0};

    for (int i = 1; i <= num; i++)
    {
        triNum += i;
    }
    return triNum;
}

int main()
{
}