class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;   // base case

        int prefixSum = 0;
        int count = 0;

        for (int x : nums) {
            if (x % 2 != 0) prefixSum++;  // count odd numbers

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
        }

        return count;
    }
};
