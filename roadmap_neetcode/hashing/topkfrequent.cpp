#include <bits/stdc++.h>
using namespace std;

//Problem: find the k most frequent elements in an array
//sol: Use hash map to organize the elements by frequency, then iterate through the frequencies in descending order to collect the top k elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        //create hashmap of  <nums, frequency>
        unordered_map <int, int> counter;
        unordered_map <int, unordered_set<int>> flip_counter;
        vector<int> ans;
        //the keys will be the elements
        for (int i=0; i<n; i++) {
            counter[nums[i]]++;
        }
        //flip keys and values of vector so we have <frequency, vector<num>>
        for (auto key: counter) {
            flip_counter[key.second].insert(key.first);
        }

        for (int i=n;i>0; i--) {
            if (flip_counter.find(i) == flip_counter.end()) continue;            
            auto it = flip_counter[i].begin(); 
            //retrieve elements until achieve k or all elements of set
            while (it != flip_counter[i].end()) {
                ans.push_back(*it);
                k--;
                it++;
                if (k == 0) return ans;
            }
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}