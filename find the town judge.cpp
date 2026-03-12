        }
        }
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0);

        for(auto &t : trust) {
            int a = t[0];
            int b = t[1];

            trustScore[a]--; // a trusts someone
            trustScore[b]++; // b is trusted
        }

        for(int i = 1; i <= n; i++) {
            if(trustScore[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};