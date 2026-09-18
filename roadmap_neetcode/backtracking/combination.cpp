//Problem: Given an array of distinct numbers and an integer target, return all combinations that sum to target. The same number may be chosen an unlimited number of times.
//Solution: Backtracking to explore possible combinations. Either we take or not the element, if we take it we leave the possibility for repeating it, if we don't take it we move to the next element.

class Solution {

private:
    vector<vector<int>> res;
    pair<vector<int>, int> subset;

    void dfs(int i, vector<int> nums, int tgt) {
        if (i == nums.size() || subset.second >= tgt) {
            if (subset.second==tgt) {
                res.push_back(subset.first);
            }
            return;
        }

        subset.first.push_back(nums[i]);
        subset.second += nums[i];
        //put number and stay at i
        dfs(i, nums, tgt);

        subset.first.pop_back();
        subset.second -= nums[i];

        //dont put number and move on to i+1
        dfs(i+1, nums, tgt);

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, nums, target);
        return res;        
    }
};
