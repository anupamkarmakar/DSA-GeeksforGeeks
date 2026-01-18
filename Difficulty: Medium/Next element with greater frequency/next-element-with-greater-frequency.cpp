class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int> mpp;
        
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mpp[arr[i]]>=mpp[st.top()]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return ans;
    }
};
