//Problem: Given a string s, find the length of the longest substring without repeating characters.
//Solution: Use a sliding window approach with two pointers. Maintain a set to track characters in the current window.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) {
            return 0;
        }

        int l=0;
        int win_size=1;
        int ans=1;
        unordered_set<char> cur_win;
        cur_win.insert(s[l]);

        for (int i=1;i<s.size();i++) {
            while (cur_win.count(s[i])) {
                cur_win.erase(s[l]);
                win_size--;       
                l++;         
            }
            cur_win.insert(s[i]);
            win_size++;
            ans = max(win_size, ans);
        }

        return ans;
    }
};