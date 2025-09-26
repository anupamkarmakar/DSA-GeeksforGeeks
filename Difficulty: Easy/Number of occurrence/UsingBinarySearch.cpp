class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int left=lower_bound(arr.begin(), arr.end(), target)-arr.begin();
        int right=upper_bound(arr.begin(), arr.end(), target)-arr.begin();
        return right-left;
    }
};
