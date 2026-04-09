#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,int>>> graph(n);

        for(auto &e : redEdges)
            graph[e[0]].push_back({e[1],0}); // red

        for(auto &e : blueEdges)
            graph[e[0]].push_back({e[1],1}); // blue

        vector<int> ans(n,-1);

        queue<pair<int,int>> q;
        q.push({0,-1});

        vector<vector<bool>> visited(n, vector<bool>(2,false));

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [node,color] = q.front();
                q.pop();

                if(ans[node] == -1)
                    ans[node] = steps;

                for(auto &[next,nextColor] : graph[node]){
                    if(nextColor != color && !visited[next][nextColor]){
                        visited[next][nextColor] = true;
                        q.push({next,nextColor});
                    }
                }
            }

            steps++;
        }

        return ans;
    }
};