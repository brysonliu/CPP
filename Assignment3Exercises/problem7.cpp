#include <iostream>

using namespace std;

int num;

int recFunc(int num)
{
    if (num == 0)
        return 0;
    else if (num < 0)
        return (-num);
    else
        return (num - recFunc(num - 5));
}

int main()
{
    cout << "Enter a number: ";
    cin >> num;
    cout << recFunc(num);
}