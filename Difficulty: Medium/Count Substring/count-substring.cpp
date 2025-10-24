class Solution {
public:
    int countSubstring(string s) {
        int n = s.size();
        int count[3] = {0}; // index 0->a, 1->b, 2->c
        
        int i = 0, result = 0, have = 0;
        
        for(int j = 0; j < n; j++) {
            count[s[j] - 'a']++; 
            
            if(count[s[j] - 'a'] == 1) 
                have++; // got a new unique character
            
            while(have == 3) {
                // we have all three characters a,b,c
                result += (n - j);
                
                count[s[i] - 'a']--;
                if(count[s[i] - 'a'] == 0)
                    have--; 
                i++;
            }
        }
        
        return result;
    }
};
