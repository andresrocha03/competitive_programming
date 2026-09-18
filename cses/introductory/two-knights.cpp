#include <bits/stdc++.h>
 
using namespace std;
 
long long calculate_possibilities(int k) {
    //calculates the number of ways two knights can be placed on a K x K board, without atacking each other.
    if (k == 1) {
        return 0;
    }
    else if (k == 2) {
        return 6;
    }
    else if (k == 3) {
        return 28;
    }
    else if (k == 4) {
        return 96;
    }
    else { 
        int four_factor = 8 + ((k-4)-1)*4; //pa
        int six_factor = 4 + ((k-4)-1)*4; //pa
        int eight_factor = (k==5)? 1:1+(3 + (3+((k-5)-1)*2))*(k-5)/2; //1 + (primeiro + ultimo)*qtd/2
        int impossibilities = 2*4 + 3*8 + 4*four_factor + 6*six_factor + 8*eight_factor;
        return ( pow(k,2)*(pow(k,2)-1) -impossibilities)/2; //divide por 2, pois a ordem não importa
    }
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long answer=0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        answer = calculate_possibilities(i);
        cout << answer << "\n";
    }
    
}