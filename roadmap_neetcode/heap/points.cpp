//Problem: return k closest points to the origin
//Sol: use a max heap to keep track of the k closest points.

class Solution {
private:
    int dist(vector<int> x) {
        return ((x[0])*(x[0]) + (x[1])*(x[1]));
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        for (vector<int> pt: points) {
            int dist_val = dist(pt);
            pq.push({dist_val, pt});
            while (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            auto pt = pq.top();
            res.push_back(pt.second);
            pq.pop();
        }
        return res;
    }
};
