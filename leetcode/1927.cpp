//Problem: We have a string (even length) with some positions having '? and others having digits. 
//Alice and Bob alternately replace the '?' with digits (0-9). If sum of left half is equal to sum of right half, Bob wins. Otherwise, Alice wins. Determine the winner.
//Solution: Count number of '?' and sum of known digits in both halves. Then, apply this formula: 2*(sr - sl) == 9*(ql - qr). 
//If this is true, Bob wins. Otherwise, Alice wins.

class Solution {
public:
    bool sumGame(string num) {
        int sl=0, sr=0, ql=0, qr=0;

        for (int i=0;i<num.size()/2;i++) {
            if (num[i]=='?') ql++;
            else sl += num[i] - '0';
        }
        for (int i=num.size()/2;i<num.size();i++) {
            if (num[i]=='?') qr++;
            else sr += num[i] - '0';
        }

        //there is no question marks - Bob wins if the sums are already equal
        if (!ql && !qr) {
            if (sl == sr) return false;
            return true;
        }

        //odd question marks
        if ((qr+ql)%2!=0) return true;

        int x = 9*(ql-qr);
        if (2*(sr - sl) == x) return false;
        return true;
    }
};