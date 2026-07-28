//Problem: Given a string and k substitutions to use how you want, what is the longest substring you can form containing one distinct character ?
//Sol: Use a sliding window (l and r) within we will always have the longest substring with one distinct character ending in r.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0;
        int maxi = 0;
        int res = 0;
        unordered_map<char, int> count;

        for (int r = 0;r<(int)s.size();r++) {
            count[s[r]]++;
            maxi = max(maxi, count[s[r]]);

            while ((r-l+1)-maxi > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, (r-l+1));
        }
        return res;
    }
};
