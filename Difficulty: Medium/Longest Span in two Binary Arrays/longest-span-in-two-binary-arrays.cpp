class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        
        unordered_map<int,int> mp;
        int prefix = 0, maxi = 0;
        
        for(int i = 0; i < n; i++) {
            prefix += (a1[i] - a2[i]);
            
            if(prefix == 0) {
                maxi = i + 1;
            }
            
            if(mp.find(prefix) != mp.end()) {
                maxi = max(maxi, i - mp[prefix]);
            } else {
                mp[prefix] = i;
            }
        }
        
        return maxi;
    }
};