//Problem: Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//Solution: Use backtracking to explore all possible paths in the grid, keeping track of visited and ensuring to match the characters in the word sequentially.

class Solution {
public:
    string cur;
    set<pair<int, int>> visited;
    int di[4] = {-1,1,0,0};
    int dj[4] = {0,0,-1,1};

    bool dfs(vector<vector<char>>& board, string word, int i, int j) {
        if (cur.length() == word.length()) {
            if (cur == word) return true;
            return false;
        }  
        

        visited.insert({i,j});
        for (int k=0;k<4;k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni >=0 && ni < board.size() && nj>=0 && nj<board[0].size() && !visited.count({ni,nj}) && board[ni][nj] == word[cur.length()]) {
                cur += board[ni][nj];
                if (dfs(board, word, ni, nj)) return true;
                cur.pop_back();
            }
        }
        visited.erase({i, j});

        return false;
    } 

    bool exist(vector<vector<char>>& board, string word) {
        cur += word[0];
        for (int i=0;i<board.size(); i++) {
            for (int j=0;j<board[0].size();j++) {
                if (board[i][j] == word[0]) {
                    visited.clear();
                    if (dfs(board, word, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};
