class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        int n = num.size();

        // Step 1: check all 9
        bool all9 = true;
        for (int x : num) {
            if (x != 9) {
                all9 = false;
                break;
            }
        }

        if (all9) {
            vector<int> res(n + 1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        vector<int> res = num;

        // Step 2: mirror left to right
        for (int i = 0; i < n / 2; i++) {
            res[n - i - 1] = res[i];
        }

        // Check if mirrored > original
        if (res > num) return res;

        // Step 3: increment middle
        int carry = 1;
        int mid = (n - 1) / 2;

        while (mid >= 0 && carry) {
            int val = res[mid] + carry;
            res[mid] = val % 10;
            carry = val / 10;
            mid--;
        }

        // Mirror again
        for (int i = 0; i < n / 2; i++) {
            res[n - i - 1] = res[i];
        }

        return res;
    }
};