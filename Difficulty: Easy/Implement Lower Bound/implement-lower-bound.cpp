class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=target) return i;
        }
        return n;
        
    }
};
