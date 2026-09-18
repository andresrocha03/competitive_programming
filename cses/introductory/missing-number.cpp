// Header de C++
 
// Biblioteca que tem tudo da STL
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   // Otimização de input
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    long long expected_sum,real_sum = 0;
    
    cin >> n;
    
    expected_sum = ((1+n)*double(n)/2.0);
    //cout << "expected "<< expected_sum << "\n";
    
    //expected_sum = expected_sum/2;
    
    
    while (cin >> x) {
        if (real_sum + x < 0) {
            cout << "real sum "<<real_sum << "\n";
            break;
        }
        real_sum += x;
        
    }
    //cout << "real sum "<<real_sum << "\n";
    if (expected_sum > real_sum) {
        cout << expected_sum - real_sum << "\n";
    }
    else {
        cout << "DEU MERDA" << "\n";
    }
    
}