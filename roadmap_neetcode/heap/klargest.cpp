//Problem: Design a class that finds the kth largest element in a stream of numbers.
//Sol: Use a min heap and store only the k largest elements.

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;    
    int k;
    
public: 
    KthLargest(int k, vector<int>& nums) {    
        this->k = k;
        for (auto num: nums) {
            this->pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
