//Problem: Given an array and a slinding window of size k, return maximum element of the window as it slides.
//Sol: Compute the maximum for the first window in linear time. Put all elements of window in a set and then always retrieve the last (maximum) element.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        set<int> wind;
        vector<int> res;
        for (int i=0;i<k;i++) {
            wind.insert(nums[i]);
        }
        res.push_back(wind.rbegin());
        for (int i=k;i<nums.size();i++) {
            wind.erase(wind.begin());
            wind.insert(nums[i]);
            res.push_back(wind.rbegin());
        }
        return res;
    }
};
