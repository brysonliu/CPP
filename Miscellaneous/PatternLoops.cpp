#include <iostream>
using namespace std;

void diamond(int size)
{
    int k, c, space = size - 1;

    for (k = 1; k <= size; k++)
    {
        for (c = 1; c <= space; c++)
            cout<< " ";

        space--;

        for (c = 1; c <= 2 * k - 1; c++)
            cout<< "*";

        cout<< "\n";
    }
    
    space = 1;
    
    for (k = 1; k <= size - 1; k++)
    {
        for (c = 1; c <= space; c++)
            cout<< " ";
    
        space++;
    
        for (c = 1 ; c <= 2 * (size - k) - 1; c++)
            cout<< "*";
    
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