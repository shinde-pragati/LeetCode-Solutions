class RecentCounter {
private:
    queue<int> requests;
    
public:
    RecentCounter() {
        // Queue starts empty
    }
    
    int ping(int t) {
        // Add current request
        requests.push(t);
        
        // Remove requests older than t - 3000
        while (requests.front() < t - 3000) {
            requests.pop();
        }
        
        // Queue size is the count of recent requests
        return requests.size();
    }
};


 
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */