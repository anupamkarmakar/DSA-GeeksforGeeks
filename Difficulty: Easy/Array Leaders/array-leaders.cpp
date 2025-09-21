

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n=arr.size();
        
        int maxright=arr[n-1];
        ans.push_back(maxright);
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxright){
                maxright=arr[i];
                ans.push_back(maxright);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};