class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size();
        sort(a.begin(),a.end());
        
        int minDiff=INT_MAX;
        for(int i=0,j=m-1 ;j<n ;j++,i++){
            minDiff = min(minDiff, a[j]-a[i]);
        }
        return minDiff;
    }
};