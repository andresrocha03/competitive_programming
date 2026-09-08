//Problem: given numbers from 1 to n, return the number of commas that would be used if the numbers were written out in the standard format
//Solution: Count number of commas by seeing how many times we can divide by 1000

class Solution {
public:
    int countCommas(int n) {
        int res = 0;

        for (int i=1;i<=n;i++) {
            int x = i;
            while (x/1000) {
                res++;
                x /= 1000;
            }
        }
        return res;
    }
};