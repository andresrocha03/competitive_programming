//Problem: given a vector of heights, in which element of index i is the height of a bar positioned at i, find the maximum area that can be calculated between two bars
//Sol: Use two pointers, one at the beggining and one at the end. Move the pointer of the smaller bar.

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;

        int res=0;
        while (l<r) {
            int area = min(heights[l], heights[r])*(r-l);
            res = max(res, area);
            if (heights[l] < heights[r]) {
                l++;
            }
            else r--;
        }
        return res;
    }
};
