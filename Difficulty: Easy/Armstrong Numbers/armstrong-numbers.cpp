// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        int sum=0,ori=n;
        while(n>0){
            int ld=n%10;
            sum+=ld*ld*ld;
            n/=10;
        }
        if(ori==sum) return true;
        else return false;
    }
};