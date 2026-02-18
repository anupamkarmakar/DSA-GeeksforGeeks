class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }
        
        vector<int> ans;
        for(int i=low; i<=high; i++){
            if(mp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};