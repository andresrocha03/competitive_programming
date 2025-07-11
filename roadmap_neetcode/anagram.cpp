//determine if two strings are anagrams of each other (same number of each character)
// Sol: use a map to count the occurrences of each character in both strings and compare them

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        bool isanagram = true;
        if (s.size() != t.size()) return false;

        for (int i=0; i<s.size(); i++) {
            if (smap.count(s[i])) {
                smap[s[i]]++;
            }
            else smap[s[i]] = 1;
        }
        for (int i=0; i<t.size(); i++) {
            if (tmap.count(t[i])) {
                tmap[t[i]]++;
            }
            else tmap[t[i]] = 1;
        }
        
        if (smap.size() != tmap.size()) return false;
        
        for (auto i : smap) {
            if (i.second != tmap[i.first]) return false;
        }
        return true;
    }
};
