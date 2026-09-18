#include <bits/stdc++.h>
 
using namespace std;
#define MAX 1000000
 
int main() {
    string sequence;
    char curr = 'j';
    long long max_length = 1.0,length = 1.0;
    
    cin >> sequence;
    int i;
    
    
    for(i=0; sequence[i]; i++){
        if (curr == sequence[i]) {
            length++;
            if (length > max_length) {
                max_length = length;
            }
        }
        else {
            curr = sequence[i];
            length = 1;
        }  
    }
    cout << max_length << "\n";
}