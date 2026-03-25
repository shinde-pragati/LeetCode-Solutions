class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        int originalColor = grid[row][col];
        
        // If already the target color, no change needed
        if (originalColor == color) {
            return grid;
        }
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS to find all cells in the connected component
        vector<vector<bool>> inComponent(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({row, col});
        inComponent[row][col] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                    !inComponent[nr][nc] && grid[nr][nc] == originalColor) {
                    inComponent[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        // Color the border cells
        vector<vector<int>> result = grid;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (inComponent[i][j]) {
                    // Check if this cell is on the border
                    bool isBorder = false;
                    
                    // Check if on grid boundary
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        isBorder = true;
                    } else {
                        // Check adjacent cells
                        for (auto [dr, dc] : dirs) {
                            int ni = i + dr;
                            int nj = j + dc;
                            // If adjacent cell is not in component, this is a border
                            if (!inComponent[ni][nj]) {
                                isBorder = true;
                                break;
                            }
                        }
                    }
                    
                    if (isBorder) {
                        result[i][j] = color;
                    }
                }
            }
        }
        
        return result;
    }
};