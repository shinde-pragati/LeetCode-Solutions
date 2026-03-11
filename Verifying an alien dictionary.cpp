class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
       
        vector<int> pos(26, 0);
        for (int i = 0; i < 26; i++) {
            pos[order[i] - 'a'] = i;
        }
     
        for (int i = 0; i < words.size() - 1; i++) {
            string& word1 = words[i];
            string& word2 = words[i + 1];
            
            int len = min(word1.length(), word2.length());
            bool foundDifference = false;
            
            for (int j = 0; j < len; j++) {
                char c1 = word1[j];
                char c2 = word2[j];
                
                if (c1 != c2) {
                
                    if (pos[c1 - 'a'] > pos[c2 - 'a']) {
                        return false; 
                    }
                    foundDifference = true;
                    break;
                }
            }
    
            if (!foundDifference && word1.length() > word2.length()) {
                return false;
            }
        }
        
        return true;
    }
};