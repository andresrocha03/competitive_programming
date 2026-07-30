//Problem: given two strings s1 and s2, check if there is a permutation of s1 inside s2
//Sol: Use a freq counter array combined with a sliding window. The window searches for s1 inside s2 by registering frequency of characters and checking mismatches.

class Solution {
public:
    int freq[256];
    int nbm = 0;

    void up(int pos, int x) {
        if (freq[pos]==0) nbm++;
        freq[pos] += x;
        if (freq[pos]==0) nbm--;
    }
 
    bool checkInclusion(string s1, string s2) {
        fill(begin(freq), end(freq), 0);

        for (int i=0;i<s1.size();i++) {
            up((unsigned int)s1[i], -1);
            up((unsigned int)s2[i], +1);
        }        
        if (nbm==0) {
            return true;
        }

        for (int i=s1.size();i<s2.size();i++) {
            up((unsigned int)s2[i-s1.size()],-1); //remove old character from window
            up((unsigned int)s2[i], +1); //add new character to the window
            if (nbm==0) {
                return true;
            }
        }

        return false;
    }
};
