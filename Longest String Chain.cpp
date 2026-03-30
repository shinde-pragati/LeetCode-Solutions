class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_map<string, int> dp;  // word -> longest chain ending at this word
        int maxChain = 1;
        
        for (const string& word : words) {
            dp[word] = 1;  // chain of just this word
            
            // Try removing each character to find a predecessor
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.count(predecessor)) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            
            maxChain = max(maxChain, dp[word]);
        }
        
        return maxChain;
    }
};