//Problem: Given a list of tasks and an integer n, solve tasks one by one, intercalating with n units of time between the same task. Return minimum amount of cycles to finish tasks.
//Solution: Use maxheap to process most frequent tasks. Use queue to store recently solved tasks and to manage the intercalation.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        //count frequencies
        vector<int> freq(26);
        for (int i=0;i<tasks.size();i++) {
            int idx = tasks[i] - 'A';
            freq[idx]++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int res=0;
        while (!pq.empty() || !q.empty()) {

            if (pq.empty() && !q.empty()) {
                res = q.front().first;
            }

            while (!q.empty() && q.front().first <= res) {
                pq.push(q.front().second);
                q.pop();
            }

            int cur = pq.top(); pq.pop();
            cur--;
            if (cur>0) {
                q.push({res+n+1,cur});
            }
            res++;
        }

        return res;        
    }
};
