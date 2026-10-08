//Problem: given two sorted arrays, find the median
//Sol: Use binary search to find a cut in the smaller array; this cut creates a set of half arrays and all elements on the left side of the cut are less than or equal to all elements on the right side of the cut.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int total = nums1.size() + nums2.size();
        int mid = (total +1)/2;

        int l=0; int r = nums1.size();
        while (l<=r) {
            int q1 = (l+r)/2;
            int q2 = mid - q1;

            int al = q1>0 ? nums1[q1-1]: INT_MIN;
            int ar = q1<nums1.size() ? nums1[q1]: INT_MAX;
            int bl = q2>0 ? nums2[q2-1]: INT_MIN;
            int br = q2 < nums2.size() ? nums2[q2]:INT_MAX;

            if (al <= br && bl <= ar) {
                if (total%2 !=0){
                    return max(al, bl);
                }
                return (max(al, bl) + min(ar,br))/2.0;
            }
            else if (al > br) {
                r = q1 -1;
            }
            else { 
                l = q1 + 1;
            }
        }
        return -1;
    }
};