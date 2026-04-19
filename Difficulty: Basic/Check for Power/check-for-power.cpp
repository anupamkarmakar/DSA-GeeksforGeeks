class Solution {
  public:
    bool isPower(int x, int y) {
        if (y == 1) return true;
        if (x == 1) return (y == 1);
        if (x == 0) return (y == 0);

        long long num = 1;

        while (num < y) {
            num *= x;
            if (num == y) return true;
        }

        return false;
    }
};