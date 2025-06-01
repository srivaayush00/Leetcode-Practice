class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int col) {
        if (vis[node] != col && vis[node] != -1) {
            return false;
        }
        vis[node] = col;
        for (auto& adjNode : adj[node]) {
            if (vis[adjNode] == -1) {
                if (!dfs(adj, vis, adjNode, 1 - col))
                    return false;
            } else if (vis[adjNode] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        // vector<vector<int>> adj(n);
        // for(int i=0;i<n;i++){
        //     int m = g[i].size();
        //     for(int j=0;j<m;j++){
        //         adj[g[i]].push_back(g[i][j]);
        //         adj[g[j]].push_back(g[i][j]);
        //     }
        // }
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (dfs(g, vis, i, 0) == false)
                    return false;
            }
        }
        return true;
    }
};