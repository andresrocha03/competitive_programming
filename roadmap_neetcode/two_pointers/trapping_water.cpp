//Problem: Given an elevation map, find maximum area of water that can be trapped between bars.
//Sol: Use two pointers, fix left pointer in i, move right pointer from i+1 to the right accounting possible water trapping, move left pointer as soon as a bar greater or equal to i is found

class Solution {
public:
    int trap(vector<int>& height) {

        int l=0, r=1;
        int res=0;
        int cur=0;
        stack<int> lefts;
        lefts.push(l);
        while (r < height.size()){
            if (height[l]<=height[r]) {
                res += cur;
                cur =0;
                lefts.pop();
                if (!lefts.empty()) {
                    l = lefts.top();
                }
                else  l=r;
            }
            else {
                cur += (height[l]-height[r]);
                l = r++;
                lefts.push(l);
            }
        }
        return res;
    }
};
