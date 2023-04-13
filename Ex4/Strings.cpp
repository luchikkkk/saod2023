#include <iostream>
#include "Str.h"
//main
using namespace std;

void Test(Str s){}

int main()
{
    char stro[10000];
    cin >> stro;
    cout << stro << endl;

    Str str1;
    Str str2 = "1 2 3";

    cout << str2 << endl;
    cout << strlen(str2) << endl;;

    Test(str2);

    cout << str2 << endl;
    cout << strlen(str2) << endl;

    Str t;
    t = str2;

    cout << str2 << endl;
    cout << strlen(str2) << endl;

    t = str2 = t;

    Str v = "4 5 6 7 8 9";

    str2 += v;

    cout << str2 << endl;
    cout << strlen(str2) << endl;

    Str st = str2 + v;

    cout << st << endl;
    cout << strlen(st) << endl;

    return 0;
}

