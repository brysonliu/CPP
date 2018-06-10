#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <cstdlib>
using namespace std;

int main()
{
    /*list<int> intList(5);
    int x = 0;

    for (auto &p : intList)
    {
        if (x % 2 == 0)
        {
            p = x * (x + 2);
        }
        else
        {
            p = (x - 1) * (x + 3);
        }
        x++;
    }

    for (auto p : intList)
    {
        cout << p << " ";
    }

    cout << endl;*/

    int numList[] = {7, 6, 9, 1, 2, 3, 4};
    vector<int> intVec;
    list<int> intList;
    //ostream_iterator<int> screen(cout, " ");

    copy(numList, numList + 7, front_inserter(intList));

    for (int i = 0; i < intList.size(); i++)
    {
        cout << intList[i] << " ";
    }

    cout << endl;

    /*intList.unique();
    
    copy(intList.begin(), intList.end(), screen);
    cout << endl;*/

    return 0;
}