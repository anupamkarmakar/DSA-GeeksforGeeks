class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>ans(n, vector<int>(n));
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<n ;j++){
                ans[i][j]=mat[j][i];
            }
        }
        
        return ans;
    }
};