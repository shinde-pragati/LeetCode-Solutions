class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> indexed; // (score, index)
        
        for (int i = 0; i < n; i++) {
            indexed.push_back({score[i], i});
        }
        
       
        sort(indexed.begin(), indexed.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        vector<string> result(n);
        
        for (int i = 0; i < n; i++) {
            int originalIndex = indexed[i].second;
            if (i == 0) {
                result[originalIndex] = "Gold Medal";
            } else if (i == 1) {
                result[originalIndex] = "Silver Medal";
            } else if (i == 2) {
                result[originalIndex] = "Bronze Medal";
            } else {
                result[originalIndex] = to_string(i + 1);
            }
        }
        
        return result;
    }
};