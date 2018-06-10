#include <iostream>

using namespace std;

void recEx11(int x)
{
    if (x > 10) 
        if (x > 0) 
        {
            recEx11((x - 3) / 2);
            cout << x << " ";
        }
        else 
        {
            recEx11((x - 4) / 2);
            cout << x << " ";
        }
}

int main()
{
    //recEx11(28);
    //recEx11(148);
    //recEx11(98);
    recEx11(-30);

    return 0;
}