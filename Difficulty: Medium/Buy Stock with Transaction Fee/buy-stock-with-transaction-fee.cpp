class Solution {
public:
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
        
        int hold = -arr[0];   // buying first stock
        int cash = 0;         // no stock
        
        for (int i = 1; i < n; i++) {
            int prev_hold = hold;
            
            hold = max(hold, cash - arr[i]);                 // buy
            cash = max(cash, prev_hold + arr[i] - k);        // sell (pay fee)
        }
        
        return cash;
    }
};