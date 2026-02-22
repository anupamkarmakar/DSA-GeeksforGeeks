class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map <int,int> mp;
        int prefixXor = 0;
        int count = 0;
        
        mp[0]=1;
        
        for(int num : arr){
            prefixXor = prefixXor ^ num;
            
            int req = prefixXor ^ k;
            
            if(mp.find(req)!=mp.end()){
                count+=mp[req];
            }
            
            mp[prefixXor]++;
        }
        
        return count;
    }
};