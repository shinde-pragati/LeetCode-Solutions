class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int num : deck) {
            count[num]++;
        }
        
        int gcdVal = 0;
        for (auto& pair : count) {
            gcdVal = gcd(gcdVal, pair.second);
            if (gcdVal == 1) {
                return false; 
            }
        }
        
        return gcdVal >= 2;
    }
};