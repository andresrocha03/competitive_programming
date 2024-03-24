#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,digits =0, order=0;
    string number;
    cin >>  n;
    

    if (n < 10) {
        cout << n;
    }

    else if (10<= n && n< pow(10,2)) {
        cout << 9 + 2*(n-9);
        
    }
    else if (pow(10,2)<= n && n< pow(10,3)) {
        
        cout << 9 + 2*90 + 3*(n-99);
    }
    else if (pow(10,3)<= n && n< pow(10,4)) {
        cout << 9 + 2*90 + 3*900 + 4*(n-999);
    }
    else if (pow(10,4)<= n && n<pow(10,5)) {
        cout << 9 + 2*90 + 3*900 + 4*9000 + 5*(n-9999);
    }
    else if (pow(10,5)<= n && n<pow(10,6)) {
        cout << 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*(n-99999);
        }
    else if (pow(10,6)<= n && n<pow(10,7)) {
        cout << 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*(n-999999);
    }
    else if (pow(10,7)<= n && n<pow(10,8)) {
        cout << 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*9000000 + 8*(n-9999999);
    }
    else if (pow(10,8)<= n && n<pow(10,9)) {
        cout << 9 + 2*90 + 3*900 + 4*9000 + 5*90000 + 6*900000 + 7*9000000 + 8*90000000 + 9*(n-99999999);
    }
    else if (n== pow(10,9)) {
        cout << "8888888899";
    }
    
}