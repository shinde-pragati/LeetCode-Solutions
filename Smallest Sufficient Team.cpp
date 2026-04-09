#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        int n = req_skills.size();
        unordered_map<string,int> skillIndex;
        
        // map skill -> bit index
        for(int i = 0; i < n; i++)
            skillIndex[req_skills[i]] = i;

        int m = people.size();
        vector<int> peopleMask(m);

        // convert each person's skills into bitmask
        for(int i = 0; i < m; i++){
            int mask = 0;
            for(string &s : people[i]){
                if(skillIndex.count(s))
                    mask |= (1 << skillIndex[s]);
            }
            peopleMask[i] = mask;
        }

        int totalMask = 1 << n;
        vector<vector<int>> dp(totalMask);

        for(int i = 0; i < m; i++){
            int personMask = peopleMask[i];

            for(int mask = 0; mask < totalMask; mask++){
                if(mask != 0 && dp[mask].empty()) continue;

                int newMask = mask | personMask;

                if(dp[newMask].empty() || dp[newMask].size() > dp[mask].size() + 1){
                    dp[newMask] = dp[mask];
                    dp[newMask].push_back(i);
                }
            }
        }

        return dp[totalMask - 1];
    }
};