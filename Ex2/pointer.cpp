#include <iostream>
#include "utils.h"

using namespace std;

int main()
{
    int x = 3, y = 5;
    int *px = &x, *py = &y;

    cout << x << ' ' << *px << ' ' << px << endl;
    px++; cout << px << endl;
    cout << px - &x << endl;
  
    typedef unsigned char byte; 	
    byte* pb = (byte*)--px;		
    for (byte* pt = pb; pt - pb < sizeof(int); pt++)
    cout << (int)*pt << ' ';	
    cout << endl;

   
    cout << "x = " << x << " y = " << y << endl;
    SwapR(*px, *py);
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}
