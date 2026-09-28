#include <bits/stdc++.h>
using namespace std;


void compute_divs(vector<vector<int>>& prime_divs) {
    
    for (int i=2;i<prime_divs.size();i++) {
        if (prime_divs[i].empty()) {
            for (int j = i; j<prime_divs.size(); j+=i) 
                prime_divs[j].push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

    vector<vector<int>> prime_divs(2e5+1);
    compute_divs(prime_divs);

    while (t--) {
        int n, k; cin >> n >> k;
        
        vector<int> nums(n);
        for (int i=0;i<n;i++) {
            cin >> nums[i];
        }
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<long long> dp(mx+1);
        for (long long i=0;i<=mx;i++){
            if (i<=k) dp[i]=0;
            else{
                dp[i] = LLONG_MAX;
                for (auto p:prime_divs[i]) {
                    dp[i] = min(dp[i], 1 + p*dp[i/p]);
                }
            }
        }    
        
        long long res = 0;
        for (auto i:nums ){
            res += dp[i];
        }

        cout << res << "\n";
    }

    return 0;
}