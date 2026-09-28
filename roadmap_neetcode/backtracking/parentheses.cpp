//Problem: Given n pairs of parentheses, return all possible combinations of well-formed parentheses.
//Solution: Use backtracking to explore all possible combinations, ensuring to respect the limit given and to always open a parentheses before closing it.


class Solution {
public:
    vector<string> res;
    string cur;

    void dfs(int n, int open, int close) {
        if (close == n) {
            res.push_back(cur);
        }

        if (open < n) {
            cur += '(';
            dfs(n,open+1, close); 
            cur.pop_back();
        }

        if (close < n && close < open) {
            cur += ')';
            dfs(n,open, close+1);
            cur.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return res;
    }
};
