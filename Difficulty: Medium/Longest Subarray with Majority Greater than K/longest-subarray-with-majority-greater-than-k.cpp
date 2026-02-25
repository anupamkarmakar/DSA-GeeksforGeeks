class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map <int,int> mp;
        int prefixsum=0, maxlen=0;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>k) prefixsum+=1;
            else prefixsum-=1;
            
            if(prefixsum>0) maxlen=i+1;
            
            if(mp.count(prefixsum-1)){
                maxlen = max(maxlen, i-mp[prefixsum-1]);
            }
            if(!mp.count(prefixsum)) mp[prefixsum]=i;
        }
        return maxlen;
    }
};