class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalArea = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                 
                    totalArea += grid[i][j] * 6;
 
                    totalArea -= (grid[i][j] - 1) * 2;
            
                    if (i + 1 < n) {
                        int minHeight = min(grid[i][j], grid[i + 1][j]);
                        totalArea -= minHeight * 2;
                    }
                    
                    if (j + 1 < n) {
                        int minHeight = min(grid[i][j], grid[i][j + 1]);
                        totalArea -= minHeight * 2;
                    }
                }
            }
        }
        
        return totalArea;
    }
};