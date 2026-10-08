//Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//Solution: Sort the array and use two pointers to find the two numbers that add up to target. Store their original indices in a vector and return it.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<pair<int,int>> nums_idx;

        for (int i=0;i<nums.size();i++) {
            nums_idx.push_back({nums[i],i});
        }
        sort(nums_idx.begin(), nums_idx.end());

        int l=0;
        int r=nums.size()-1;

        while (l<r) {
            int sum = nums_idx[l].first + nums_idx[r].first;
            if (sum == target) {
                res.push_back(nums_idx[l].second);
                res.push_back(nums_idx[r].second);
                break;
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }

        return res;
    }
};