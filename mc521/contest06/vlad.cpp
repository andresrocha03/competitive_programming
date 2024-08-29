#include <iostream> 
using namespace std; 

#define N 200005
int dp[N];

int sum_digit(int n) {
    int sum = 0;
    while (n>0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests, input;

    dp[1] = 1;
    for (int i=0; i<N; i++) {
        dp[i] = dp[i-1] + sum_digit(i);
    }

    cin >> tests;

    for (int i=0; i<tests; i++) {
        cin >> input;
        cout << dp[input];
        cout << "\n";
    }     
    
}