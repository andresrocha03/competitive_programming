//Problem: Given an array of integers (may vontain duplicates) and an integer target, return unique combinations that sum to target.
//Solution: Sort the candidate array and use backtracking to explore possible solutions, but after exploring a path, skip to the next distinct number to avoid duplicated paths.

class Solution {

private:
    vector<vector<int>> res;
    pair<vector<int>,int> subset;

    void dfs(int i, vector<int> nums, int target) {
        if (subset.second >= target) {
            if (subset.second == target) {
                res.push_back(subset.first);
            }
            return;
        }

        //put num i 

        for (int j=i;j<nums.size();j++) {
            if (j > i && nums[j-1] ==nums[j]) {
                continue;        
            }
            subset.first.push_back(nums[j]);
            subset.second += nums[j];
            dfs(j+1, nums, target);
            subset.first.pop_back();
            subset.second -= nums[j];
        }

        return;

    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res;
    }
};
