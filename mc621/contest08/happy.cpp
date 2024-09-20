#include <bits/stdc++.h>
using namespace std;


#include <utility>


int z, i, m, l;

int f(int x) {
    int sum = 0;
    while (x>0) {
        sum += pow(x%10,2);
        x /= 10;
    }
    return sum;
}


// a funcao abaixo foi retirada dos slides da aula
// Function to find the start (mu) and length (lambda) of a cycle
int floydCycleFinding(int x0) {
    // 1st part: Finding the meeting point inside the cycle
    int tortoise = f(x0);          // tortoise moves at 1x speed
    int hare = f(f(x0));           // hare moves at 2x speed

    while (tortoise != hare && hare != 1) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }

    if (hare==1) return 1 ;
    else return 0;

    // // 2nd part: Finding mu, the start of the cycle
    // int mu = 0;
    // hare = x0;
    // while (tortoise != hare) {
    //     tortoise = f(tortoise);
    //     hare = f(hare);
    //     mu++;
    // }

    // // 3rd part: Finding lambda, the length of the cycle
    // int lambda = 1;
    // hare = f(tortoise);
    // while (tortoise != hare) {
    //     hare = f(hare);
    //     lambda++;
    // }

    // return std::make_pair(mu, lambda);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    
    int j=1,t, happy;
    cin >> t;
    while (t--) {
        cin >> l;
        happy = floydCycleFinding(l);
        if (happy)         cout << "Case #" << j << ": " << l << " is a Happy number.\n";
        else         cout << "Case #" << j << ": " << l << " is an Unhappy number.\n";
        j++;
    }


    return 0;
}