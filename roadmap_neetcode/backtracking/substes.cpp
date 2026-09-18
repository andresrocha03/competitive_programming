//Problem: Given a set of unique numbers, generate all possible subsets (the power set).
//Solution: Use backtracking to expore all possible combinations (all possible paths in a decision tree).


class Solution {

private:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(int i, vector<int> nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return ;
        }

        //put element at index i in the subset
        subset.push_back(nums[i]);
        dfs(i+1, nums);
        subset.pop_back();

        //skip element i and go to the next one
        dfs(i+1,nums);

        return ;
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
