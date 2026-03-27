class Solution {
public:
    void dfs(int node, int parent, vector<int>& vis,
             vector<int>& tin, vector<int>& low,
             vector<int>& mark, vector<vector<int>>& adj,
             int &timer) {
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;

        for (auto it : adj[node]) {
            if (it == parent) continue;

            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj, timer);
                
                low[node] = min(low[node], low[it]);

                // articulation condition
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } 
            else {
                low[node] = min(low[node], tin[it]);
            }
        }

        // root node case
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(V, 0), tin(V), low(V), mark(V, 0);
        int timer = 0;

        // handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj, timer);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        if (ans.size() == 0) return {-1};
        return ans;
    }
};