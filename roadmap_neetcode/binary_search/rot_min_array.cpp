//Problem: Given an array sorted in ascending order and rotated n times. Find the minimum element
//Sol: Use binary search to find maximum element, the min element is max_idx + 1.

class Solution {
    public:
        int findMin(vector<int> &nums) {
            int a =0;


            //check if the array is sorted or if it only has one element
            if  (nums.size() == 1 || nums[0] < *nums.rbegin()) return nums[0];

            //array is rotated
            for (int x=(int)nums.size()/2; x>=1 ;x/=2) {
                while (nums[a+x]>nums[a]) a+= x;
            }
            return nums[a+1];
        }
};
