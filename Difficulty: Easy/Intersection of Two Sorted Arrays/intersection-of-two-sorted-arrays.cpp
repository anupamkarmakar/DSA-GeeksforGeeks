class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (i > 0 && a[i] == a[i - 1]) {
                i++; 
                continue;
            }

            if (a[i] < b[j]) {
                i++;
            }
            else if (a[i] > b[j]) {
                j++;
            }
            else {
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};