class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        if(arr[0]!=1) return 1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=(arr[i+1]-1)){
                return arr[i]+1;
            }
        }
        return arr[n-1]+1;
    }
};