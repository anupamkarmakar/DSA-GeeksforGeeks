class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }
        
        vector<int> visited(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) continue;

            unordered_map<int, int> mp;
            int node = i;
            int step = 0;

            while (node != -1) {
                if (visited[node]) break;

                visited[node] = 1;
                mp[node] = step++;

                int next = adj[node];

                if (next != -1 && mp.count(next)) {
                    ans = max(ans, step - mp[next]);
                    break;
                }

                node = next;
            }
        }

        return ans;
    }
};