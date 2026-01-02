class Solution {
  public:
    void solve(int n, string res, vector<string> &ans){
        if(res.size()==n){
            ans.push_back(res);
            return;
        }
        
        solve(n,res+'0',ans);
        solve(n,res+'1',ans);
    }
    
    vector<string> binstr(int n) {
        vector<string> ans;
        solve(n,"",ans);
        return ans;
        
    }
};