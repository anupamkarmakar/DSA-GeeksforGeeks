class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);

        // Fill buckets
        for(int c : citations) {
            if(c >= n)
                bucket[n]++;
            else
                bucket[c]++;
        }

        // Traverse from high to low
        int papers = 0;
        for(int i = n; i >= 0; i--) {
            papers += bucket[i];
            if(papers >= i)
                return i;
        }

        return 0;
    }
};