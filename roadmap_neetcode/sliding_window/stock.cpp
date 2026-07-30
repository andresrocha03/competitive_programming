//Problem: We have an array of integer values representing daily prices of a stock. Find the maximum possible difference between selling and buying prices (profit).
//Sol: Use a sliding window. When the sell price is bigger than buy price, compute profit and compare with the best so far. Otherwise, (sell<buy) we change our buy day.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0;
        int res =0;
        for (int r=1;r<(int)prices.size();r++) {
            if (prices[r] >= prices[l]) {
                res = max((prices[r]-prices[l]), res);
            }
            else l = r;
        }
        return res;
    }
};
