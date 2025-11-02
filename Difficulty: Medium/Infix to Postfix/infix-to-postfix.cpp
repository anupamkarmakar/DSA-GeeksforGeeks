class Solution {
  public:
    int presedence(char ch){
        if(ch=='+' || ch=='-') return 1;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='^') return 3;
        else return 0;
    }
    
    string infixToPostfix(string& s) {
        stack <char> st;
        string result="";
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            
            if(isalnum(c)){
                result+=c;
            }
            
            else if(c=='('){
                st.push(c);    
            }
            
            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
            }
            
            else{
                while(!st.empty() && (presedence(c)<presedence(st.top()) || (c!='^' &&  presedence(c)==presedence(st.top()))) && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
