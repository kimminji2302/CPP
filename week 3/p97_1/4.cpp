#include <iostream>
int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for (int k = 4; k >= i; k--)
        {
            std::cout << " ";
        }
        for (int s=0; s<i; s++)
        {
            std::cout << i - s;
        }
        for (int j=2; j<=i; j++)
            std::cout <<j;
        std::cout << "\n";
    }
    return 0;
}