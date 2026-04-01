#include <iostream>
#include <algorithm>

std:: string reverse(std::string s);

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << reverse(s) << std::endl;

    return 0;
}

std:: string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}