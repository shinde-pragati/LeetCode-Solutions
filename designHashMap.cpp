class MyHashMap {
private:
    vector<list<pair<int, int>>> buckets;
    int numBuckets;
    
    int hash(int key) {
        return key % numBuckets;
    }
    
public:
    MyHashMap() {
        numBuckets = 10000;  
        buckets.resize(numBuckets);
    }
    
    void put(int key, int value) {
        int index = hash(key);
 
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                kv.second = value;  
                return;
            }
        }
        
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        
        return -1;  // Key not found
    }
    
    void remove(int key) {
        int index = hash(key);
        
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */