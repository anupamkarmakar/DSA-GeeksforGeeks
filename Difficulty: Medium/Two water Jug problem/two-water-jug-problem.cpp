class Solution {
  public:
    int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// simulate pouring from fromJug -> toJug
int pour(int fromJug, int toJug, int d) {
    int from = fromJug;
    int to = 0;
    int step = 1; // first step = fill fromJug

    while (from != d && to != d) {
        int temp = min(from, toJug - to);
        to += temp;
        from -= temp;
        step++;

        if (from == d || to == d)
            break;

        if (from == 0) {
            from = fromJug;
            step++;
        }

        if (to == toJug) {
            to = 0;
            step++;
        }
    }

    return step;
}

int minSteps(int m, int n, int d) {
    if (d > max(m, n)) return -1;
    if (d % gcd(m, n) != 0) return -1;

    return min(pour(m, n, d), pour(n, m, d));
}
};