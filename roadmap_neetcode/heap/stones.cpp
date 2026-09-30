//Problem: Given an array, merge or destroy two biggest at each round until there is only one or none element left in the array.
//Solution: Use a max heap to easily retrieve the two biggest elements at each round.

class Solution {
private:
    priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int>& stones) {
        for (int num:stones) {
            pq.push(num);
        }
       
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            if (x==y) continue;
            else{
                if (y < x) swap(x,y);
                y -= x;
                pq.push(y);
            }
        }


        if (!pq.size()) return 0;
        return pq.top();
    }
};
