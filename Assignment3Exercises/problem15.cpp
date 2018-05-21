#include <iostream>

using namespace std;

int test(int x, int y)
{
    if (abs(x - y) <= 1)
        return x + y;
    else if (x > y)
        return test(x - 1, y + 1);
    else if (y > x)
        return test(x + 1, y - 1);
}

int main()
{
    //cout << test(8, 2) << endl;
    cout << test(5, 16) << endl;
    //cout << test(-25, 2) << endl;
    //cout << test(8, -6) << endl;
    //cout << test(-20, -36) << endl;

    return 0;
}