#pragma once
#include <iostream>

using namespace std;

class Test
{
public: 

    static int nCount;

    Test()
    {
        nCount++;
        cout << "created" <<endl;
        cout << nCount << endl;
    }

    ~Test()
    {
        nCount--;
        cout << "deleted" << endl;
        cout << nCount << endl;
    }
};

