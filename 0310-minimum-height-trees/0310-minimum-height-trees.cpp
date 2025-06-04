class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0)
            return {0};
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(degree[i] == 1)
                q.push(i);
        }




        while (!q.empty()) {
            int sz = q.size();
            ans.clear(); 
            for (int i = 0; i < sz; i++) {
                int node = q.front(); q.pop();
                ans.push_back(node);
                for (auto &neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) q.push(neighbor);
                }
            }
        }


        return ans; 


    }
};