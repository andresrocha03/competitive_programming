//Problem: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
//Solution: Use backtracking to explore all possible partitions, checking if each substring is a palindrome and add it to the current partition if so.

class Solution {
private:
    vector<vector<string>> result;
    vector<string> currentPartition;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }


    void dfs( int start, const string& s) {
        if (start == s.size()) {
            result.push_back(currentPartition);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                string substring = s.substr(start,end - start + 1);
                currentPartition.push_back(substring);
                dfs(end + 1,s);
                currentPartition.pop_back();
            }
        }
    }


public:

    vector<vector<string>> partition(string s) {
        int startingIndex = 0;
        dfs(startingIndex, s);
        return result;
    }
};