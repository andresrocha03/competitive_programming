#include <bits/stdc++.h>
using namespace std;






multiset<int> ms;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    string op;
    int x;
    while (q--) {
        cin >> op >> x;
        switch (op) {
            case ('+'):
                ms.insert(x);
                break;
            case('?'):
                maxor(x);
                break;
            case('-'):
                ms.erase(x);
                break;

        }
    }


    return 0;
}