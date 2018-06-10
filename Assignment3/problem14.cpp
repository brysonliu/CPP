#include <iostream>

using namespace std;

void recFun(int x, int y)
{
    if (x > 0 && y > 0)
    {
        if (x >= y && y != 0)
        {
            cout << x % y << " ";
            recFun(x - y, y);
        }
        else if (y > x && x != 0)
        {
            cout << y % x << " ";
            recFun(y - x, x);
        }
    }
    else 
        cout << x + y << endl;
}

int main()
{
    //recFun(180, 38);
    //recFun(75, 26);
    //recFun(13, 86);
    recFun(56, 148);

    return 0;
}