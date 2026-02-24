class Solution {
public:
    vector<string> findWords(vector<string>& words) {
     
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> rowMap;
        
        for (int i = 0; i < rows.size(); i++) {
            for (char c : rows[i]) {
                rowMap[c] = i;       
                rowMap[toupper(c)] = i; 
            }
        }
        
        vector<string> result;
        
        for (string& word : words) {
            if (word.empty()) continue;
            int row = rowMap[word[0]];
            bool sameRow = true;
            for (char c : word) {
                if (rowMap[c] != row) {
                    sameRow = false;
                    break;
                }
            }
            if (sameRow) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};