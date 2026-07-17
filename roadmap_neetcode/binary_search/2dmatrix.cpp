//Problem: Given a 2D matrix, determine if a target number is present in it
//Sol: Use binary search on the 2D matrix by treating it as a 1D array.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l =0, r = (matrix.size()*matrix[0].size()) - 1;
        int k;
        int cols = matrix[0].size();
        while (l <= r) {
            k = (l+r)/2;
            int row = k/cols;
            int column = k%cols;
            if (matrix[row][column]==target) break;
            else if (target < matrix[row][column]) r = k-1; 
            else l = k+1;
        }    

        if (l>r) return false;
        return true;
    }
};
