//Problem: Given a string, find the longest unique substring
//Sol: Use two pointers to create a sliding window that will always contain a string with unique characters.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.size()==0) return 0;

        int bl, br;
        int l=0;
        int r;
        int ans = 1;
        unordered_set<char> seen; seen.insert(s[l]);

        for (int r=1;r<s.size();r++) {
            if (seen.count(s[r])) { //founded repeated char
                ans = max(ans, (int)seen.size()); //size of set is the size of string with unique characters found
                while (seen.count(s[r])) { //erase until I can continue my search without having repeated elements
                    seen.erase(s[l]);
                    l++;
                }
            }
            
            seen.insert(s[r]);
        }
        
        return ans;
    }
};
