class Solution {
public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};

        vector<int> smaller(n, -1), greater(n, -1);

        // Find smaller element on left for every index
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIdx]) {
                minIdx = i;
            } else {
                smaller[i] = minIdx;
            }
        }

        // Find greater element on right for every index
        int maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIdx]) {
                maxIdx = i;
            } else {
                greater[i] = maxIdx;
            }
        }

        // Find valid triplet
        for (int i = 0; i < n; i++) {
            if (smaller[i] != -1 && greater[i] != -1) {
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }

        return {};
    }
};