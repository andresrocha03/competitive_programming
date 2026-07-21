//Problem: Given an array, sorted and rotated n times, find the target element.
//Sol: Use bin search to determine which interval to search in. Check limits of intervals to find out whether it is sorted or not and if target is in it.

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size()-1;
            
            while (l<=r) {
                int m = (l+r)/2;
                if (nums[m] == target) return m;

                if (nums[m]<=nums[r]) {
                    if (target > nums[m] && target <= nums[r]) l = m+1;
                    else r = m-1;
                }
                
                else if (nums[m]>=nums[l]) {
                    if (target >= nums[l] && target < nums[m]) r = m-1;
                    else l = m+1;
                }
            }

            return -1;
        }
};