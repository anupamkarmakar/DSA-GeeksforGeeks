class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
      
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int time = 0;
       
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            time++; // one minute passed
        }
        
        // Step 3: Check if all are rotten
        return (fresh == 0) ? time : -1;
    }
};