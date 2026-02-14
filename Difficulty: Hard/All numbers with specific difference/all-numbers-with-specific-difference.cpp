class Solution {
  public:
    int digitSum(long long x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int getCount(int n, int d) {
        if (d > n) return 0;

        long long ans = 0;
        // Check only the critical small range
        int upper = min(n, d + 89);
        for (int i = d + 1; i <= upper; i++) {
            if (i - digitSum(i) >= d) {
                ans++;
            }
        }

        // All numbers from (d + 90) to n are valid
        if (n >= d + 90) {
            ans += (n - (d + 90) + 1);
        }
        return ans;
    }
};


