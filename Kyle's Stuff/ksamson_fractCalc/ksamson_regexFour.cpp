#include <regex>
#include <iostream>

using namespace std;

// regex_iterator
// regex_token_iterator

/*************** Regex Iterators ***************/

int main()
{
    string str = "2/3+5/6; 2/3*5/6;; 2/3/5/6";

    regex e("(\d)[/](\d)([+|\-|*|/])(\d)[/](\d)", regex_constants::grep|regex_constants::icase );

    cout << regex_replace(str, e, "$1 is on $2 ", regex_constants::format_no_copy|regex_constants::format_first_only);

    /*
    sregex_token_iterator pos(str.cbegin(), str.cend(), e, -1);
    sregex_token_iterator end;
    for (; pos!=end; pos++)
    {
        cout << "Matched: " << pos->str() << endl;
        //cout << "user name: " << pos->str(1) << endl;
        //cout << "Domain: " << pos->str(2) << endl;
        cout << endl;
    }
    */

    cout << "================================\n\n";

    cin >> str;
}