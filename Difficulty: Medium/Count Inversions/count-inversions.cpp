class Solution {
  public:
    
    long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int i = l, j = m + 1;
        long long inv = 0;

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv += (m - i + 1);
            }
        }

        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++)
            arr[k] = temp[k - l];

        return inv;
    }

    long long mergeSortCount(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;

        int m = (l + r) / 2;
        long long inv = 0;

        inv += mergeSortCount(arr, l, m);
        inv += mergeSortCount(arr, m + 1, r);
        inv += mergeAndCount(arr, l, m, r);

        return inv;
    }

    int inversionCount(vector<int> &arr) {
        return mergeSortCount(arr, 0, arr.size() - 1);
    }
};
