#include <bits/stdc++.h>
using namespace std;


#include <utility>


int z, i, m, l;

int f(int x) {
    return (z*x +i)%m;
}


// a funcao abaixo foi retirada dos slides da aula
// Function to find the start (mu) and length (lambda) of a cycle
std::pair<int, int> floydCycleFinding(int x0) {
    // 1st part: Finding the meeting point inside the cycle
    int tortoise = f(x0);          // tortoise moves at 1x speed
    int hare = f(f(x0));           // hare moves at 2x speed

    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    // 2nd part: Finding mu, the start of the cycle
    int mu = 0;
    hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }

    // 3rd part: Finding lambda, the length of the cycle
    int lambda = 1;
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


    cin >> z >> i >> m >> l;

    int j=1;
    while (m) {
        pair<int,int> ans = floydCycleFinding(l);
        cout << "Case " << j << ": " << ans.second << "\n";
        j++;
        cin >> z >> i >> m >> l;
    }





    return 0;
}