#include <iostream>
int main()
{
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 4; j >= i; j--)
        {
            std::cout << " ";
        }
        for (int l = 0; l <= i -1; l++)
        {
            std::cout << i - l;
        }
        std::cout << "\n";
    }
      return 0;
}
