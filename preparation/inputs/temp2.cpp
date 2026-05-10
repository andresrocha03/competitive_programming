#include <bits/stdc++.h>
using namespace std;

int main() {

    string date;
    int maxt = -51;
    int mint = 51;
    while (cin >> date) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int t;
        while (ss >> t) {
            maxt = max(maxt, t);
            mint = min(mint, t);
        }
    }

    cout << mint << " " << maxt << " \n";

    return 0;
}