#include <bits/stdc++.h>
using namespace std;
#include <utility>

// #define long long long long

long long a, b, x, n;

long long f(long long x) {
    return ((a*(((x%n)*(x%n))%n))%n + b%n)%n ;
}


// a funcao abaixo foi retirada dos slides da aula
// Function to find the start (mu) and length (lambda) of a cycle
std::pair<long long, long long> floydCycleFinding(long long x0) {
    // 1st part: Finding the meeting polong long inside the cycle
    long long tortoise = f(x0);          // tortoise moves at 1x speed
    long long hare = f(f(x0));           // hare moves at 2x speed

    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // 2nd part: Finding mu, the start of the cycle
    long long mu = 0;
    hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    // 3rd part: Finding lambda, the length of the cycle
    long long lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare);
        lambda++;
    }

    return std::make_pair(mu, lambda);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    while (n) {
        pair<long long,long long> ans = floydCycleFinding(0);
        cout << n-ans.second << "\n";
        cin >> n;
        if (a) cin >> a>> b;
    }

    return 0;
}