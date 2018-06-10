#include <iostream>

using namespace std;

void funcEx8(int u, char v)
{
    if (u == 0)
        cout << u << " ";
    else 
    {
        int x = static_cast<int>(v);

        if (v < 'A')
            v = static_cast<char>(x + 1);
        else if (v > 'Z')
            v = static_cast<char>(x - 1);

        cout << v << " ";

        funcEx8(u - 2, v);
    }
}

int main()
{
    // funcEx8(26, '$');
    funcEx8(11, 'B');
    // funcEx8(18, '^');

    return 0;
}