class Solution {
public:
    string URLify(string &s) {
        string result = "";
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')
                result += "%20";
            else
                result += s[i];
        }
        
        return result;
    }
};