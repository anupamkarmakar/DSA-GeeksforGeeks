class Solution {
public:
    string removeSpaces(string& s) {
        int j = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                s[j] = s[i];
                j++;
            }
        }
        
        return s.substr(0, j);
    }
};