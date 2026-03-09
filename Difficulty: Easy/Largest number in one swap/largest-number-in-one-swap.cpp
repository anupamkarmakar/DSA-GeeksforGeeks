class Solution {
public:
    string largestSwap(string s) {
        vector<int> last(10, -1);
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            last[s[i] - '0'] = i;
        }

        for(int i = 0; i < n; i++){
            for(int d = 9; d > s[i] - '0'; d--){
                if(last[d] > i){
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }

        return s;
    }
};