class Solution {
  public:
    int atmost(vector<int> arr, int k){
        int odd=0;
        int count=0;
        int left=0;
        
        for(int right=0; right<arr.size(); right++){
            if(arr[right]%2!=0){
                odd++;
            }
            
            while(odd>k){
                if(arr[left]%2!=0) odd--;
                left++;
            }
            
            count+= right-left+1;
        }
        return count;
    }
    
    int countSubarrays(vector<int>& arr, int k) {
        return atmost(arr,k)-atmost(arr,k-1);
    }
};