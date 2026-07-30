//Problem: Given two strings s and t, find min substring in s that contains all characters from t.
//Sol: Use an array to compute chars frequencies. When we find all searched characters, reduce window until is valid, then keep searching.

class Solution {
public:
    int freq[256]{};
    int nbm = 0;

    void up(unsigned char pos, int action) {
        if (action == 1) {
            // Add character to window
            if (freq[pos] < 0)
                nbm--;

            freq[pos]++;
        } else {
            // Remove character from window
            freq[pos]--;

            if (freq[pos] < 0)
                nbm++;
        }
    }

    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size())
            return "";

        fill(freq, freq + 256, 0);
        nbm = 0;

        for (char c : t) {
            freq[static_cast<unsigned char>(c)]--;
            nbm++;
        }

        int l = 0;
        int best_l = 0;
        int best_wsz = INT_MAX;

        for (int r = 0; r < static_cast<int>(s.size()); r++) {
            up(static_cast<unsigned char>(s[r]), 1);

            // While the window contains all required characters
            while (nbm == 0) {
                int wsz = r - l + 1;

                if (wsz < best_wsz) {
                    best_wsz = wsz;
                    best_l = l;
                }

                up(static_cast<unsigned char>(s[l]), -1);
                l++;
            }
        }

        if (best_wsz == INT_MAX)
            return "";

        return s.substr(best_l, best_wsz);
    }
};