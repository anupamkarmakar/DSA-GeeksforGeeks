class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) sum += x;

        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 != 0) return 0;

        int req = (target + sum) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int num : arr) {
            for (int j = req; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[req];
    }
};