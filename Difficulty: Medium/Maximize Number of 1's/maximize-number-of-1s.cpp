class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int count0=0;
        int maxlen=0;
        
        for(int j=0,i=0; j<n; j++){
            if(arr[j]==0) count0++;
            
            while(count0>k){
                if(arr[i]==0) count0--;
                i++;
            }
            
            maxlen = max(maxlen, j-i+1);
        }
        
        return maxlen;
    }
};
