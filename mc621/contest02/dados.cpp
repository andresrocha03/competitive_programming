#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> v, int k)
{
    queue<int> q;

    int m = INT_MIN;
    int sum = 0;
    int index = 0;

    for (int i = 0; i < k; i++) {
        q.push(v[i]);
        sum += v[i];
    }

    for (int i = k; i < v.size(); i++) {
        if (sum > m) {
            index = i-1;        
        }
        m = max(m, sum);
        sum -= q.front();
        q.pop();
        q.push(v[i]);
        sum += v[i];

    }
    m = max(m, sum);
    return index;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x;

    vector<int> v;
    vector<int> diff;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }


    for (int i=0; i<v.size()-1; i++) {
        diff.push_back(abs((v[i+1] - v[i])));
    }

    for (int i=0; i<diff.size()-1; i++) {
        diff[i] = -diff[i];
    }

    int index = maxSum(v, k);
    cout << index << "\n";
    for (int i=index-1-k; i<index-1; i++) {
        cout << i;
    }
    cout << "\n";

    return 0;
}