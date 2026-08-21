//Problem: Given an array, detect if there is any duplicates. Array size is n+1 and values are between 1 and n.
//Sol: Treat the array as a linked list with n+1 nodes. Array[i] is the next node from node i. Then we use Floyd's detection algorithm and find the entrance to the cycle.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]];
        int slow = nums[0];

        while (fast != slow) {
            slow = nums[slow]; //jumps 1 node
            fast = nums[nums[fast]]; //jumps 2 nodes
        }

        int slow2 =0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
