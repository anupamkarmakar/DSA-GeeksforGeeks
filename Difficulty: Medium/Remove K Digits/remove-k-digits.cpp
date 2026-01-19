class Solution {
  public:
    string removeKdig(string &s, int k) {
        stack<char> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && (st.top()-'0')>s[i]-'0'){
                k--;
                st.pop();
            }
            st.push(s[i]);
        }
        
        while(k>0 && !st.empty()){
            k--;
            st.pop();
        }
        
        if(st.empty()) return "0";
        
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        while(!res.empty() && res.back()=='0') res.pop_back();
        
        if(res.empty()) return "0";
        
        reverse(res.begin(),res.end());
        return res;
    }
};