// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=x) return i;
        }
        return -1;
    }
};