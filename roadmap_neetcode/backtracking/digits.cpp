//Probem: Given a string of digits and a digit mapping to some chars, what are all possible char combinations that this digit string could be representing
//Solution: Use backtracking to explore all possible solutions/combinations

class Solution {
private:
    vector<string> res;
    string cur;

    unordered_map<char, string> mp = {
        {'0', " "}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9',"wxyz"}
    };



    void dfs(string digits) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }

        string candidates = mp[digits[cur.size()]];

        for (auto c: candidates) {
            cur += c;
            dfs(digits);
            cur.pop_back();
        }
    
    }


public:
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return res;
        dfs(digits);
        return res;    
    }
};
