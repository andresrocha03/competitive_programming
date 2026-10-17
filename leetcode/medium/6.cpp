//Problem: Given a string, convert it into a string s2 that reflects a zigzag pattern with an also given number of rows.
//Sol: We can use a vector of strings and assing characters to different rows.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        
        vector<string> rows(numRows);
        int dir = 1;
        int row = 0;


        for (auto c: s) {
            rows[row] += c;
            if ((row==(numRows-1) && dir==1) || (row==0 && dir==-1)) dir *= (-1);
            row += dir;
        }

        string res;
        for (string row_str:rows) {
            res += row_str;    
        }

        return res;
    }
};