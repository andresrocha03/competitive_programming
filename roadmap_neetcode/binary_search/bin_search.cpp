//Problem: determine if a given number is present in an array
//Sol: Use binary search 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int k;
        while (l<=r) {
            k = (l+r)/2;
            if (nums[k]==target) break;
            else if (target<nums[k]) r = k-1;
            else l = k+1;
        }
        if (l>r) return -1;
        return k;
    }
};
