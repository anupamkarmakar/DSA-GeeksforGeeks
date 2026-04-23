class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int total = 0;
        for (int x : arr) total += x;
    
        if (total % 2 != 0) return false;
    
        int target = total / 2;
        int prefix = 0;
    
        for (int i = 0; i < arr.size() - 1; i++) {
            prefix += arr[i];
            if (prefix == target) return true;
        }
    
        return false;
    }
};
