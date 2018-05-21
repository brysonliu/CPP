#include <iostream>

using namespace std;

int recEx13(int x)
{
    if (x <= 0)
        return 0;
    else if (x == 1)
        return 2;
    else 
        return (recEx13(x - 1) + recEx13(x - 2) + recEx13(x - 3));
}

int main()
{
    //cout << recEx13(-2) << endl;
    //cout << recEx13(3) << endl;
    //cout << recEx13(4) << endl;
    cout << recEx13(5) << endl;

    return 0;
}