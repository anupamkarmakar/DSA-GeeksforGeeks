class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        int l=0, r=0;
        int maxlen=0;
        unordered_map <int,int> mp;
        while(r<n){
            mp[arr[r]]++;
            
            while(mp.size()>2 && l<n){
                if(mp[arr[l]]>1){
                    mp[arr[l]]--;
                } else{
                    mp.erase(arr[l]);
                }
                l++;
            }
            
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};