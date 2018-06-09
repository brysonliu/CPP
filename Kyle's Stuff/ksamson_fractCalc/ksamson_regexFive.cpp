//Example 1
#include <iostream>
#include <string>
#include <regex>

int main ()
{
    std::string str("2/3+5/6");
    std::regex r("(\d)");
    std::smatch m;
    std::regex_search(str, m, r);
    for(auto v: m) std::cout << v << std::endl;
}