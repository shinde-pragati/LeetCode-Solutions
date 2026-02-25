class Solution {
private:
    vector<vector<int>> graph;
    vector<vector<int>> criticalEdges;
    vector<int> discoveryTime;
    vector<int> lowTime;
    vector<bool> visited;
    int time = 0;
    
    void dfs(int node, int parent) {
        visited[node] = true;
        discoveryTime[node] = lowTime[node] = ++time;
        
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            
            if (!visited[neighbor]) {
                dfs(neighbor, node);
        
                lowTime[node] = min(lowTime[node], lowTime[neighbor]);
                
                if (lowTime[neighbor] > discoveryTime[node]) {
                    criticalEdges.push_back({node, neighbor});
                }
            } else {
             
                lowTime[node] = min(lowTime[node], discoveryTime[neighbor]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
        graph.resize(n);
        for (const auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
      
        discoveryTime.resize(n, -1);
        lowTime.resize(n, -1);
        visited.resize(n, false);
      
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
        
        return criticalEdges;
    }
};