//Problem: given an array of distinct integers, return all possible permutations
//Solution: Use backtracking and keep record of numbers already used with an unordered_set.

class Solution {

private:
    vector<vector<int>> res;
    pair<unordered_set<int>, vector<int>> subset;
   
    void dfs(vector<int> nums) {
        if (subset.second.size()==nums.size()) {
            res.push_back(subset.second);
            return;
        }

        for (int i=0;i<nums.size();i++) {
            if (subset.first.count(i)==0) {
                subset.first.insert(i);
                subset.second.push_back(nums[i]);
                dfs(nums);
                subset.first.erase(i);
                subset.second.pop_back();
            }    
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
};
