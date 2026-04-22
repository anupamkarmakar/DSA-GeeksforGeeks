class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

    // Step 1: Build prefix sum
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Step 2: Process queries
    vector<int> result;
    for (auto &q : queries) {
        int l = q[0], r = q[1];

        long long sum = prefix[r + 1] - prefix[l];
        int len = r - l + 1;

        result.push_back(sum / len); // floor automatically
    }

    return result;
    }
};