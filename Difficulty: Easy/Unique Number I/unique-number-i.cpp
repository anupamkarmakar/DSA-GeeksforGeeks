class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        if(arr[0]!=arr[1]) return arr[0];
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]) return arr[i];
        }
        return arr[arr.size()-1];
    }
};