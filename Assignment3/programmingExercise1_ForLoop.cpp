#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int size;

    cout << endl;
    cout << "How large do you want the table to be? ";
    cin >> size;
    cout << endl;

    for (int i = size; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << left << "*";
        }

        cout << endl;
    }    
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << left << "*";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}