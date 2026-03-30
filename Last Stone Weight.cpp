class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;  // max-heap
        
        // Push all stones into the heap
        for (int stone : stones) {
            pq.push(stone);
        }
        
        // Continue until at most one stone remains
        while (pq.size() > 1) {
            int y = pq.top(); pq.pop();  // heaviest
            int x = pq.top(); pq.pop();  // second heaviest
            
            if (x != y) {
                pq.push(y - x);
            }
            // If x == y, both are destroyed (nothing to push)
        }
        
        return pq.empty() ? 0 : pq.top();
    }
};