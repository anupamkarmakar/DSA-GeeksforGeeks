class Solution {
  public:
    int maxProfit(vector<int> &p) {
        // code here
        int n=p.size();
        stack<int> st;
        int pf=0, maxpf=0,buy;
        
        for(int i=0;i<n;i++){
            
            
            while(!st.empty() && p[i]<st.top()){
                st.pop();
            }
            
            if(st.empty()) buy=p[i];
            st.push(p[i]);
            
            if(!st.empty()){
                pf = st.top() - buy;
                maxpf = max(maxpf,pf);
            }
        }
        return maxpf;
    }
};
