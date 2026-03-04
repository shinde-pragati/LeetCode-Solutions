class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        while (i >= 0 || j >= 0) {
         
            int backspaceCount = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    backspaceCount++;
                    i--;
                } else if (backspaceCount > 0) {
                    backspaceCount--;
                    i--;
                } else {
                    break;
                }
            }
     
            backspaceCount = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    backspaceCount++;
                    j--;
                } else if (backspaceCount > 0) {
                    backspaceCount--;
                    j--;
                } else {
                    break;
                }
            }
      
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            }
           
            else if (i >= 0 || j >= 0) {
                return false;
            }
            
            i--;
            j--;
        }
        
        return true;
    }
};