#include <iostream>

using namespace std;

void recFun(int u)
{
    if (u == 0)
        cout << "Zero! ";
    else 
    {
        cout << "Negative ";
        recFun(u + 1);
    }
}

int main()
{
    //recFun(8);
    //recFun(0);
    recFun(-2);

    return 0;
}