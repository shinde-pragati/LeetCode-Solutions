class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(days.begin(), days.end());
        
        vector<int> dp(368, 0); 
        
        for (int day = 365; day >= 1; day--) {
            if (travelDays.find(day) == travelDays.end()) {
              
                dp[day] = dp[day + 1];
            } else {
                
                int cost1 = costs[0] + dp[day + 1];
                int cost7 = costs[1] + dp[min(366, day + 7)];
                int cost30 = costs[2] + dp[min(366, day + 30)];
                
                dp[day] = min({cost1, cost7, cost30});
            }
        }
        
        return dp[1];
    }
};