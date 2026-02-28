class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;   // last bit
        n /= 2;
        
        while(n > 0) {
            int curr = n % 2;
            
            if(curr == prev)
                return false;
                
            prev = curr;
            n /= 2;
        }
        
        return true;
    }
};