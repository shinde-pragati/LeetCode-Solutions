class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> count(52, 0); 
        
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                count[c - 'a']++;
            } else {
                count[c - 'A' + 26]++;
            }
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (int freq : count) {
            if (freq % 2 == 0) {
                length += freq;
            } else {
                length += freq - 1;
                hasOdd = true;
            }
        }
         if (hasOdd) {
            length++;
        }
        
        return length;
    }
};