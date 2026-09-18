#include <bits/stdc++.h>
 
using namespace std;
 
void print_vector(vector<int> v, int n) {
    //prints the vector
    for (int i=1; i<=n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j = 2,aux;
    cin >> n;
    if (n > 4) {
        vector<int> v(n+1);
        int plus[3] = {0,1,-1};
 
        for (i=0; i<n+1; i++) {
            v[i] = i;
        }
        for (i = 1; i <n; i++) {
            if (i+j < n +1) {
                aux = v[i];
                v[i] = v[i+j];
                v[i+j] = aux;
                j += plus[j];    
            }
        }
        print_vector(v,n);
    }
    else {
        if (n == 1) {
            cout << "1" << "\n";
        }
        if (n == 4) {
            cout << "3 1 4 2" << "\n";
        }
        else {
            cout << "NO SOLUTION" << "\n";
            cout << "\n";
        }
    }
}