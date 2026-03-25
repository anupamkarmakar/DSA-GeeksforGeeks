class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        
        // Edge case
        if (V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Push all leaf nodes
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = V;

        // Remove leaves layer by layer
        while (remainingNodes > 2) {
            int size = q.size();
            remainingNodes -= size;

            while (size--) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    degree[neighbor]--;

                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};