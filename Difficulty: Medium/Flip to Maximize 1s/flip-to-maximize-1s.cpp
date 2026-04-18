class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        
        int totalOnes = 0;
        for(int x : arr) {
            if(x == 1) totalOnes++;
        }
        
        int maxSum = 0, currSum = 0;
        
        for(int i = 0; i < n; i++) {
            int val = (arr[i] == 0) ? 1 : -1;
            
            currSum = max(val, currSum + val);
            maxSum = max(maxSum, currSum);
        }
        
        return totalOnes + maxSum;
    }
};