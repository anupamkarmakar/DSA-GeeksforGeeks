class Solution {
  public:
    // Last Seen Minimum Tracking” approach part of "Two-pointer / Sliding Window family"

    int countSubstring(string s) {
        int n=s.size();
        int count=0;
        int lastseen[3]={-1,-1,-1};
        
        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                count= count+ min({lastseen[0],lastseen[1],lastseen[2]}) +1;
            }
        }
        return count;
        
    }
};