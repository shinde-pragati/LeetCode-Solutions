class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
     
        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++, k--) {
            nums[i] = -nums[i];
        }
      
        if (k % 2 == 1) {
      
            int minIndex = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            nums[minIndex] = -nums[minIndex];
        }
      
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
};