class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int v : adj[node]) {
            if (vis[v] == -1)
                dfs(v, adj, vis, st);
        }
        st.push(node);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        vector<int> vis(V, -1);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (vis[i] == -1) {
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> topologicalSort;
        while (!st.empty()) {
            topologicalSort.push_back(st.top());
            st.pop();
        }
        return topologicalSort;
    }
};