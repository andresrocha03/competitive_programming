//Problem: given a vector of strings, group the anagrams together
//Solution: use a map to store the sorted version of each string as the key and the a vector of the original strings as the values

class Solution {
public:

    string keygen(string s) {
        int charCount[26]={0};
        string key = s;

        // count quantity of each character in the string
        for (int i=0; i<s.length(); i++) {
            charCount[s[i]-'a']++;
        }

        // generate key (sorted string)
        int idx = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < charCount[i]; j++) {
                key[idx] = 'a' + i;
                idx++;
            }
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> idxs;
        vector<vector<string>> ans;

        //sort string to create key and save list of strings
        for (int i=0; i<strs.size(); i++) {
            string s = strs[i];
            string key = keygen(s);
            idxs[key].push_back(s);
        }

        // create vector for output
        for (auto i : idxs) {
            ans.push_back(i.second);
        }

        return ans;
    }


};
