#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests,y,x;
    long long diag_number = 1,answer = 0, last_number = 0;
    
    cin >> tests;
    for (int i=tests; i>0; i--) {
        cin >> x >> y;
        if (y != x) { //fora da diagonal         
            if (x > y) {// triangulo inferior à diagonal
                last_number = 2 + ((x-1)-1)*2; //an = a1 + (n-1)*r --> pa para o incremento da diagonal 
                diag_number = 1 + (2+last_number)*(x-1)/2; //x-1 é a qtd de elementos
                if (x%2 == 0) {
                    answer = diag_number + (x-y); //o numero x representa, aqui nessa operacao, a "coluna da diagional"
                }
                else {
                    answer = diag_number - (x-y);
                }
            }
            else { //triangulo superior à diagonal
                last_number = 2 + ((y-1)-1)*2; //an = a1 + (n-1)*r --> pa para o incremento da diagonal 
                diag_number = 1 + (2+last_number)*(y-1)/2; //x-1 é a qtd de elementos
                if (y%2 == 0) {
                    answer = diag_number - (y-x); //o numero y representa, aqui nessa operacao, a "coluna da diagional"
                }
                else {
                    answer = diag_number + (y-x);
                }
            }
            
        }
        else { //numero sobre a diagonal
            last_number = 2 + ((x-1)-1)*2; //an = a1 + (n-1)*r --> pa para o incremento da diagonal 
            diag_number = 1 + (2+last_number)*(x-1)/2; //x-1 é a qtd de elementos    
            answer = diag_number;
        }
        cout << answer << "\n";
    }
}