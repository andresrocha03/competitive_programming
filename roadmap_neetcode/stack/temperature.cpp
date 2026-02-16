//Problem: given an array A of integers return an array B, in which the ith element represents the distance between A[i] and the first bigger than A[i] element
//Solution: Montonic decreasing stack for keeping track of indexes. If we find a bigger element, reverse compute indexes.
//O(n) time complexity, O(n) space complexity

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i=0; i<n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]){
                int index = st.top();
                st.pop();
                res[index] = i - index;
            }
            st.push(i);
        }

        return res;
    }
};
