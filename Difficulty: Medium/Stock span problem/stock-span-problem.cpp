class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int> st;
        vector<int> ans;
        int count;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) count=i-(-1);
            else count=i-st.top();
            
            st.push(i);
            
            ans.push_back(count);
        }
        return ans;
        
    }
};