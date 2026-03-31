// 1번
#include <iostream>
int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        // std::cout << i << "\n";
        for(int j = 1; j <= i; ++j)
        {
            std::cout << j;
        }
        std::cout << "\n";
    }
}
