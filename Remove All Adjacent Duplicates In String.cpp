class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                // Current character matches the last one in result → remove it
                result.pop_back();
            } else {
                // No match → add current character
                result.push_back(c);
            }
        }
        
        return result;
    }
};