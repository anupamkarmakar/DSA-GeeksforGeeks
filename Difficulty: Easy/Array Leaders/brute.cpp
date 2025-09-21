class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]) break;
                else if (j==n-1)  ans.push_back(arr[i]);
            }
        }
        ans.push_back(arr[n-1]);
        return ans;
    }
};