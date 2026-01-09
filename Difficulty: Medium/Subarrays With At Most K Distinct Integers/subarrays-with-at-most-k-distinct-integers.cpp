class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n=arr.size();
        int left=0;
        int count=0;
        unordered_map<int,int> mp;
        
        for(int right=0;right<n;right++){
            mp[arr[right]]++;
            
            while(mp.size()>k){
                mp[arr[left]]--;
                
                if(mp[arr[left]]==0)
                    mp.erase(arr[left]);
                left++;
            }
            
            count+=(right-left+1);
        }
        return count;
    }
};