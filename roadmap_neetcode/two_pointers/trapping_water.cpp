//Problem: Given an elevation map, find maximum area of water that can be trapped between bars.
//Sol: Use two pointers, left pointer at the begin and right and right at the end, they will limit the maximum amount of water that can be trapped in a certain position

class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0; 
        int r = height.size()-1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;
        while (l<r){
            if (height[l]<=height[r]) {
                lmax = max(lmax, height[l]);
                res += lmax - height[l];
                l++;
            }
            else {
                rmax = max(rmax, height[r]);
                res += rmax - height[r];
                r--;
            }
        }
        return res;
    }
};
