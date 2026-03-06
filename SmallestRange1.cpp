class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        int newMin = minVal + k;
        int newMax = maxVal - k;
        
   
        if (newMin >= newMax) {
            return 0;
        }
    
        return newMax - newMin;
    }
};