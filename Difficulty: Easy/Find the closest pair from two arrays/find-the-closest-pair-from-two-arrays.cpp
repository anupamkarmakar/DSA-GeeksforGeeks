class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n=arr1.size(), m=arr2.size();
        int i=0, j=m-1;
        int minDiff=INT_MAX;
        vector<int>ans;
        
        while(i<n && j>=0){
            int sum=arr1[i]+arr2[j];
            int diff=abs(sum-x);
            
            if(diff<minDiff){
                minDiff=diff;
                ans={arr1[i],arr2[j]};
            }
            
            if(sum>x) j--;
            else i++;
        }
        return ans;
    }
};