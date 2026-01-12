//Problem: given an array, what is the longest consecutive sequence that can be formed
//Sol: use to sets

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            set<int> getmin;
            unordered_set<int> deposit;
            size = nums.size();

            if (size == 0) return 0;

            for (int i=0; i<size; i++) {
                getmin.insert(nums[i]);
                deposit.inser(nums[i]);
            }

            int res = 1;
            int count = 1;
            while (!getmin.empty()) {
                int min = *getmin.begin();
                getmin.erase(min);
                deposit.erase(min);
                
                // if next consecutive number exists, increment count
                count = (deposit.count(min+1) > 0) ? count + 1 : 1;
                
                if (count > res) res = count;
            }

            return res;
        }

};