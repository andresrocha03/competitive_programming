//Problem: determine if there is a duplicate in a vector
//Sol: use an  unordered_set to check for duplicates in O(1) time complexity
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check;

        bool repeat = false;

        for (int i=0;i<nums.size();i++) {
            int x = nums[i];
            if (check.find(x) == check.end()) {
                check.insert(x);
            }
            else if (check.find(x) != check.end()) {
                repeat = true;
                break;
            }
        }

        return repeat;
    }
};