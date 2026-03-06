class Solution {
public:
    string minWindow(string &s, string &p) {
        int n = s.size(), m = p.size();

        vector<int> hash(256,0);
        for(char ch : p) {
            hash[ch]++;
        }

        int left = 0, right = 0;
        int startIdx = -1, minlen = INT_MAX;
        int count = 0;

        while(right < n) {

            if(hash[s[right]] > 0)
                count++;

            hash[s[right]]--;

            while(count == m) {

                if(right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    startIdx = left;
                }

                hash[s[left]]++;

                if(hash[s[left]] > 0)
                    count--;

                left++;
            }

            right++;
        }

        if(startIdx == -1) return "";

        return s.substr(startIdx, minlen);
    }
};