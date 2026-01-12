//Problem: find two indices such that the numbers at those indices add up to a target value
// Sol: use an unordered_map to store the numbers and their indices, then check for the difference between the target and each number

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> check;
        vector<int> diff;
        int n = nums.size();
        vector<int> ans(2);

        for (int i=0; i<n; i++) {
            check[nums[i]] = i;
            diff.push_back(target - nums[i]);
        }

        for (int i=0; i<n; i++) {
            auto it = check.find(diff[i]);
            if ((it != check.end()) && (it->second != i)) {
                ans[0] = i;
                ans[1] = it -> second;
                break;
            }
        }

        return ans;
    }
};
