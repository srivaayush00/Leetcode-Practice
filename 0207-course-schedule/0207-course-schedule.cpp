class Solution {
private:
    bool dfsCheck(vector<vector<int>>& adj, vector<int>& vis,
                  vector<int>& pathVis, int node) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto& adjNode : adj[node]) {
            if (vis[adjNode] == -1) {
                if (dfsCheck(adj, vis, pathVis, adjNode) == true) {
                    return true;
                }
            } else if (pathVis[adjNode] != -1) {
                return true;
            }
        }
        pathVis[node] = -1;
        return false;
    }
private:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        int n = V;
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V, -1);
        vector<int> pathVis(V, -1);

        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                if (dfsCheck(adj, vis, pathVis, i) == true) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return !isCyclic(numCourses, prerequisites);
    }
};