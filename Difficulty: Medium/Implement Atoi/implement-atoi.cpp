class Solution {
public:
    int myAtoi(string &s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        
        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits
        long long num = 0;  // use long long to detect overflow
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // 4. Handle overflow
            if (num > INT_MAX / 10 || 
               (num == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            num = num * 10 + digit;
            i++;
        }
        
        return (int)(sign * num);
    }
};