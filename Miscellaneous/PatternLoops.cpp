#include <iostream>
using namespace std;

void star(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int l = 0; l < size; l++)
    {
        for (int m = 0; m <= l; m++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    star(5);
    return 0;
}