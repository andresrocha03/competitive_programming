#include <bits/stdc++.h>
using namespace std;


int main( ) {
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    sort(a, a+2);

    for (int i=0;i<10;i++) cout << a[i];

    return 0;
}