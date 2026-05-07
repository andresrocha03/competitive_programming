#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> ms;

    string line;
    string mon;
    while (getline(cin, line)) {
        mon = line.substr(11);
        ms.insert(mon);
    }
    cout << ms.size() << "\n";

    return 0;
}