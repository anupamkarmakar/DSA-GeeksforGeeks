class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set <int> s;
        
        for(int num : a) s.insert(num);
        for(int num : b) s.insert(num);
        
        vector<int> ans;
        ans.assign(s.begin(),s.end());
        
        return ans;
    }
};