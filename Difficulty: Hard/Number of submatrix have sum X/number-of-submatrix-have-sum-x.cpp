class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Step 1: prefix sum
        vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = mat[i-1][j-1]
                          + pre[i-1][j]
                          + pre[i][j-1]
                          - pre[i-1][j-1];
            }
        }
        
        int count = 0;
        int maxSize = min(n, m);
        
        // Step 2: try all square sizes
        for (int k = 1; k <= maxSize; k++) {
            for (int i = 0; i + k - 1 < n; i++) {
                for (int j = 0; j + k - 1 < m; j++) {
                    
                    int r1 = i, c1 = j;
                    int r2 = i + k - 1, c2 = j + k - 1;
                    
                    long long sum = pre[r2+1][c2+1]
                                  - pre[r1][c2+1]
                                  - pre[r2+1][c1]
                                  + pre[r1][c1];
                    
                    if (sum == x) count++;
                }
            }
        }
        
        return count;
    }
};