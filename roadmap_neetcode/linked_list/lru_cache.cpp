//Problem: Design a LRU cache supporting get and put operations.
//Sol: Hash map to store key-value pairs and a double linked list to keep track of the order of usage.

class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> updates;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (this->cache.contains(key)) { //if key exists
            this->updates.erase(this->cache[key].second);
            this->updates.push_back(key);
            this->cache[key].second = --this->updates.end();
            return this->cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->cache.find(key) != this->cache.end()) {
            updates.erase(cache[key].second);
            
        } else if (this->cache.size() == this->capacity) {
            this->cache.erase(this->updates.front());
            this->updates.pop_front();
        }
        this->updates.push_back(key);
        this->cache[key] = {value, --this->updates.end()};
    }
};
