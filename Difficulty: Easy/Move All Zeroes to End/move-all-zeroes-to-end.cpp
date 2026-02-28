class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
        
        while(i<n){
            while(i<n && arr[i]==0) i++;
            if(i<n){
                arr[j]=arr[i];
                j++,i++;
            } 
        }
        
        while(j<n){
            arr[j]=0;
            j++;
        }
        
    }
};