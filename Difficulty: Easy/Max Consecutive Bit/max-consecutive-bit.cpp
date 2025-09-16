class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int n=arr.size();
        int c0=0,c1=0;
        int max0=0,max1=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                c1=0;
                c0++;
            }
            else if(arr[i]==1){
                c0=0;
                c1++;
            }
            if(max0<c0) max0=c0;
            if(max1<c1) max1=c1;
        }
        return (max0>max1)?max0:max1;
    }
};