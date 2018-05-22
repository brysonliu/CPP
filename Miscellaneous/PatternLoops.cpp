#include <iostream>
using namespace std;

void diamond(int size)
{
    int k, c, space = size * 2 - 2;

    for (k = 1; k <= size; k++)
    {
        for (c = 1; c <= space; c++)
            cout<< " ";

        space = space - 2;

        for (c = 1; c <= 2 * k - 1; c++)
            cout<< "* ";

        cout<< "\n";
    }
    
    space = 2;
    
    for (k = 1; k <= size - 1; k++)
    {
        for (c = 1; c <= space; c++)
            cout<< " ";
    
        space = space + 2;
    
        for (c = 1 ; c <= 2 * (size - k) - 1; c++)
            cout<< "* ";
    
        cout<< "\n";
    }
}

int main()
{
    int size;
    cout << endl << "Size of pattern: ";
    cin >> size;
    cout << endl;
    diamond(size);
    cout << endl;
    return 0;
}