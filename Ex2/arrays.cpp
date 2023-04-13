
#include <iostream>

using namespace std;

void rotate(int a[], int n);

int main()
{
     int a[5]{ 1,2,3,4,5 };
    int n = *(&a + 1) - a;
    int* pn = &n;
    for (int i = 0; i < *pn; i++) {
        cout << a[i] << ' ';
    }
    
    cout <<"N: " << *pn << ' ';
    cout << endl;
    
    rotate(a, *pn);

    for (int *p = a; p - a < 5; p++)
        cout << *p << ' ';
    cout << endl;

    return 0;
}

void rotate(int a[], int n) {
    int x = a[0];
    for (int i = 1; i < n; i++)
        a[i - 1] = a[i];
    a[n - 1] = x;
}
