class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n=arr.size();
        
        // Window XOR
        int windowXOR=0;
        for(int i=0;i<k;i++){
            windowXOR^=arr[i];
        }
        
        int maxopt=windowXOR;
        for(int i=k;i<n;++i){
            windowXOR^=arr[i-k]; //remove the outside element
            windowXOR^=arr[i]; //add the next 
            maxopt=max(maxopt,windowXOR);
        }
        
        return maxopt;
        
    }
};