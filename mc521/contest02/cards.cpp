#include <bits/stdc++.h>

using namespace std;

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0);
    std::string word;
    int n;
    int os=0;
    int ns=0;

    cin >> n;
    cin >> word;

    for (int i=0; i<n; i++){
        if (word[i] == 'o') {
            os++; 
        }
        if (word[i] == 'n') {
            ns++;
        }
     
    }   

    for (int i=0; i<ns; i++) {
        cout << 1 << " ";
    }
    for (int i=0; i<os-ns; i++) {
        cout << 0 << " ";
    }

    return 0;
}
