//Problem: Given a string, find longest palindromic substring
//Sol: For eah character, strat two pointers and expland to check what is the biggest palindrome that we can make


class Solution {
private:
    string check(int i, int j, string s){
        string res = "";
        s.substr(i,j-i);
        while (i>=0 && j<s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        
        return s.substr(i+1,j-i-1);
    }

public:
    string longestPalindrome(string s) {
        string res = "";

        for (int i=0;i<s.size();i++) {
            string s1 = check(i,i,s);
            if (s1.size() > res.size()) res = s1;

            string s2 = check(i, i+1, s);
            if (s2.size() > res.size()) res = s2;
        }

        return res;
    }
};