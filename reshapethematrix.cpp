class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(); 
         int n = mat[0].size();       
        if (m * n != r * c) {
            return mat;  
        }
       
        vector<vector<int>> reshaped(r, vector<int>(c));

        for (int i = 0; i < m * n; i++) {

            int originalRow = i / n;
            int originalCol = i % n;
 
            int newRow = i / c;
            int newCol = i % c;
            
            reshaped[newRow][newCol] = mat[originalRow][originalCol];
        }
        
        return reshaped;
    }
};