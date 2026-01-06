class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        
        if(n<k) return -1;
        
        // Find sum of first kth element
        int windowSum=0;
        for(int i=0;i<k;i++){
            windowSum+=arr[i];
        }
        
        // Slide the window, add the next element and remove the element going out of the window
        int maxsum=windowSum;
        for(int i=k;i<n;i++){
            windowSum=windowSum+arr[i]-arr[i-k];
            maxsum=max(maxsum,windowSum);
        }
        
        return maxsum;
    }
};