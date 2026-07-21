//Problem: Create a time-based key-value store that can store multiple values for the same key at different timestamps and retrieve the value at a given timestamp.
//Sol: Use a hash map to store the key and a vector of pairs (timestamp, value) for each key. Use binary search to find the value at a given timestamp.

class TimeMap {
    public:
        unordered_map<string, vector<pair<string, int>>> mp;

        TimeMap() {};
        
        void set(string key, string value, int timestamp) {
            mp[key].push_back({value, timestamp});
        }
        
        string get(string key, int timestamp) {
            if (!mp.count(key)) return "";
            vector<pair<string, int>>& vec = mp[key];

            int x = -1;

            for (int b=vec.size();b>=1;b/=2) {
                while (x+b < vec.size() && vec[x+b].second <= timestamp) x += b;
            }
            if (x == -1) return "";
            return vec[x].first;
        }
};
