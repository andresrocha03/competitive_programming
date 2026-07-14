//Problem: Given an array of numbers and a target, find two elements whose sum is target
//Sol: Use two pointers, one at the beggining and another at the end, increase left pointer or increase right pointer

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left = 0;
        int right = numbers.size()-1;
        vector<int> res;
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum > target) {
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else if (sum == target) {
                res.push_back(++left);
                res.push_back(++right);                
                break;
            }
        }
        return res;
    }
};
