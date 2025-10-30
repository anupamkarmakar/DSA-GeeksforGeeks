class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int> vec ;
        
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
        
        sort(vec.begin(),vec.end());
        
        for(int x : vec){
            st.push(x);
        }
        
    }
};
