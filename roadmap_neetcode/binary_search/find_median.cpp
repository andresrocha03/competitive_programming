//Problem: given two sorted arrays, find the median
//Sol: Use binary search to find a cut in the smaller array; this cut creates a set of half arrays and all elements on the left side of the cut are less than or equal to all elements on the right side of the cut.

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int>& a = nums1;
            vector<int>& b = nums2;

            if (a.size() > b.size()) {
                swap(a,b);
            }

            int total = a.size() + b.size();
            int half = (total + 1)/2;

            int l = 0; int r = a.size();
            while (l<=r) {
                int q1 = (l+r)/2; int q2 = half - q1;
                
                int alef = q1 > 0 ? a[q1-1] : INT_MIN;
                int aright = q1 < a.size() ? a[q1]: INT_MAX;
                int blef = q2 > 0 ? b[q2-1] : INT_MIN;
                int bright = q2 < b.size() ? b[q2]: INT_MAX;

                if (alef <= bright && blef <= aright) {
                    if (total%2 != 0) {
                        return max(alef, blef);
                    }
                    return (max(alef, blef) + min(aright, bright))/2.0;
                
                } else if (alef > bright) {
                    r = q1-1;
                
                } else {
                    l = q1 + 1;
                }
            }
            return -1;

        }
};