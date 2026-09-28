//Problem: Return all possible subsets given an array with integers that may contain duplicates.
//Solution: Sort the input array, use backtracking to explore possible combinations, skip duplicates by avoiding choosing equal numbers at the same recursive depth.

class Solution {

private:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(int i, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        //include number
        subset.push_back(nums[i]);
        dfs(i+1, nums);
        subset.pop_back();

        //avoid duplicated subsets here
        while (i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }

        //do not include number
        dfs(i+1, nums);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       dfs(0, nums);
       return res; 
    }
};
