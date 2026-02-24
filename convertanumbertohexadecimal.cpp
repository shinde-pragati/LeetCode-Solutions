class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        string hexChars = "0123456789abcdef";
        string result = "";
        
        unsigned int n = num;  
        
        while (n != 0) {
            
            int digit = n & 0xF;
            result = hexChars[digit] + result;
            n >>= 4; 
        }
        
        return result;
    }
};