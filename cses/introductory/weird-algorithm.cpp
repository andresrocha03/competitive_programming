// Header de C++
 
// Biblioteca que tem tudo da STL
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x;
    cin >> x;
    cout << x << " ";
    while (x != 1) {
        if (x%2 == 0) {
            x = x/2;
        }
        else {
            x = x*3 + 1;
        }
        if (x < 0) {
            break;
        }
        cout << x << " ";
    }
    cout << "\n";
    
}