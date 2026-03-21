class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Sort the array
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
      
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        
        // Step 3: Map value → index
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[sorted[i]] = i;
        }
        
        // Step 4: Compute result
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int idx = index[arr[i]];
            
            int left = idx;
            int right = n - idx - 1;
            
            result.push_back(dp[left] * dp[right]);
        }
        
        return result;
    }
};