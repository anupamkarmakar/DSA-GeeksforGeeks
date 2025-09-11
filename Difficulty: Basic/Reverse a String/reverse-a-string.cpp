// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n=s.length();
        for(int i=0,j=n-1;i<j;i++,j--){
            swap(s[i],s[j]);
        }
        return s;
    }
};
