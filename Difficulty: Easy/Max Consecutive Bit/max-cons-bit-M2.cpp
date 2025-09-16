class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        int n=arr.size();
        int count=1,maxCount=0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) count++;
            else{
                maxCount=max(maxCount,count);
                count=1;
            }
        }
        return max(maxCount,count);
    }
};
