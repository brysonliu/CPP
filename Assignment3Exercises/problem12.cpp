#include <iostream>

using namespace std;

int recEx12(int a, int b)
{
    if (a < b)
        return a + b;
    else 
        return recEx12(a - b, b + 1);
}

int main()
{
    //cout << recEx12(128, 15) << endl;
    //cout << recEx12(-10, 8) << endl;
    //cout << recEx12(148, 78) << endl;
    cout << recEx12(25, 25) << endl;

    return 0;
}