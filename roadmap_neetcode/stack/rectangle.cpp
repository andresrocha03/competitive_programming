//Problem: given a list of rectangles' heights, find the largest rectangle that can be formed by adjacent rectangles.
//Solution: use a stack to keep track of how far we can extend a rectangle

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> idxs;
        int best = 0;

        idxs.push_back(0);
        for (int i=1;i<heights.size();i++) {
            if (heights[i] >= heights[idxs.back()]) idxs.push_back(i);
            else {
                while (heights[i] < heights[idxs.back()] && !idxs.empty()) {
                    int h = heights[idxs.back()];
                    idxs.pop_back();
                    int left = idxs.empty() ? -1 : idxs.back();
                    int w = i  - left - 1;
                    int area = h*w;
                    best = max(area, best);
                }
                idxs.push_back(i);
            }
        }

        int last = heights.size();
        while (!idxs.empty()) {
            int h = heights[idxs.back()];
            idxs.pop_back();
            int left = idxs.empty() ? -1 : idxs.back();
            int w = last  - left - 1;
            int area = h*w;
            best = max(area, best);
        }
        
        return best;
        
    }
};
