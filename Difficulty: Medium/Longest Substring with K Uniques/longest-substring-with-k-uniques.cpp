class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size();
        unordered_map <char,int> mp;
        int maxlen=-1;
        
        for(int i=0,j=0; i<n; i++){
            mp[s[i]]++;
            
            if(mp.size()==k){
                maxlen=max(maxlen,i-j+1);
            }
            
            while(j<n && mp.size()>k){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
        }
        return maxlen;
    }
};