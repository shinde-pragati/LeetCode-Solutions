class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60] = {0};
        int result = 0;
        
        for (int t : time) {
            int r = t % 60;
            int need = (60 - r) % 60;
            result += count[need];
            count[r]++;
        }
        
        return result;
    }
};