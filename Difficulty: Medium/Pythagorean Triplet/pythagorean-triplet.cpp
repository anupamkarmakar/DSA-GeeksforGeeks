class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        const int MAX = 1000;
        vector<bool> present(MAX+1, false);
        
        for(int x : arr)
            present[x] = true;

        for(int a = 1; a <= MAX; a++){
            if(!present[a]) continue;

            for(int b = a; b <= MAX; b++){
                if(!present[b]) continue;

                int c2 = a*a + b*b;
                int c = sqrt(c2);

                if(c*c == c2 && c <= MAX && present[c])
                    return true;
            }
        }

        return false;
    }
};