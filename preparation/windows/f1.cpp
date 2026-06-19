#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll oo = 1e18 + 5;

int main() {
    int n, m;
    vector<int> fs, ss;

    for (int i=0;i<n;i++) {
        cin >> fs[i] >> ss[i];
    }

    currS = -oo;
    currF = 0;
    deque<int> nxts = {0};
    deque<int> cwe;

    for (int i=0;i<n;i++) {
        currF += fs[i];
        currS = max(currS, ss[i]);

        if (ss[i] > ss[nxts.back()]) {
            while (!nxts.empty() && ss[i]>ss[nxts.back()]) {
                nxts.pop_back();
            }
        }


    }


    return 0;
}