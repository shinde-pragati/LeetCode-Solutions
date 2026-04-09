#include <vector>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> right(m, vector<int>(n,0));
        vector<vector<int>> down(m, vector<int>(n,0));
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1){
                    right[i][j] = 1 + (j+1<n ? right[i][j+1] : 0);
                    down[i][j] = 1 + (i+1<m ? down[i+1][j] : 0);
                }
            }
        }
        
        int maxSide = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int small = min(right[i][j], down[i][j]);
                
                for(int k = small; k > maxSide; k--){
                    if(right[i+k-1][j] >= k && down[i][j+k-1] >= k){
                        maxSide = k;
                    }
                }
            }
        }
        
        return maxSide * maxSide;
    }
};