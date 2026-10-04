//Problem: Given an array of integers, finds the kth largest element.
//Sol: Use a min heap and store only the k largest elements.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num:nums) {
            pq.push(num);
            while (pq.size() >  k ) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
