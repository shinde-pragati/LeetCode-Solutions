class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int n = s.length();
        
        int start = 0;
        for (int i = 1; i <= n; i++) {
            // If we're at the end or character changes
            if (i == n || s[i] != s[start]) {
                int length = i - start;
                if (length >= 3) {
                    result.push_back({start, i - 1});
                }
                start = i; // Start new group
            }
        }
        
        return result;
    }
};