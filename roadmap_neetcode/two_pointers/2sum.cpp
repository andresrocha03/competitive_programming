//Problem: Given an array of numbers, find all unique triplets that sum to zero
//Sol: Compute sums and check if their negative exist in the input array of numbers

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            for (int i=0;i<nums.size()-2;i++) {
                if (i > 0 && nums[i] == nums[i - 1]) {
                   continue;
                }

                if (nums[i] > 0) {
                    break;
                }

                int l=i+1;
                int r=nums.size()-1;
                int tgt = -nums[i];
                while (l < r) {
                    long long sum =
                        static_cast<long long>(nums[i]) + nums[l] + nums[r];

                    if (sum == 0) {
                        res.push_back({nums[i], nums[l], nums[r]});

                        int leftValue = nums[l];
                        int rightValue = nums[r];

                        while (l < r && nums[l] == leftValue) {
                            l++;
                        }

                        while (l < r && nums[r] == rightValue) {
                            r--;
                        }
                    } else if (sum < 0) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
            return res;
        }
};
