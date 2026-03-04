class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Complete Morse code mapping for a-z
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                                "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                                "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
                                "...-", ".--", "-..-", "-.--", "--.."};
        
        unordered_set<string> transformations;
        
        for (const string& word : words) {
            string transformation = "";
            for (char c : word) {
                transformation += morse[c - 'a'];  // 'a' maps to index 0
            }
            transformations.insert(transformation);
        }
        
        return transformations.size();
    }
};