#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums;
    int n;
    for (int i=0; i<7; i++) {
        cin >> n;
        nums.push_back(n);
    }

    sort(nums.begin(), nums.end());

    cout << nums[0] << " " << nums[1] << " " << nums[6] - nums[0] - nums[1];

    return 0;
}