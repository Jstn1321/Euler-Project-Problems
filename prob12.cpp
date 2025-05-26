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

int numFactors(int num)
{
    int numFact{0};
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            numFact++;
        }
    }
    return numFact;
}

int main()
{
    int num = 1;
    while (true)
    {
        if (numFactors(triangleNumGen(num)) >= 500)
        {
            break;
        }
        std::cout << triangleNumGen(num) << "\n";
        num++;
    }

    std::cout << triangleNumGen(num);
}