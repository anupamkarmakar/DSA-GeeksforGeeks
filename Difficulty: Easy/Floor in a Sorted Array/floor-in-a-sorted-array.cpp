class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(arr[i]<=x) return i;
        }
        return -1;
    }
};
