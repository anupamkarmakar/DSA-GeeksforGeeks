class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxEle = arr[0];
        for(int ele : arr){
            if(ele>maxEle) maxEle=ele;
        }
        return maxEle;
    }
};
