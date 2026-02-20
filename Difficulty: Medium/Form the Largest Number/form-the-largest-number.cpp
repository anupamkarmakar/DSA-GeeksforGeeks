class Solution {
  public:
    static bool cmp(string a, string b){
        return a+b > b+a;
    }
    
    string findLargest(vector<int> &arr) {
        
        vector<string> str;
        for(int a : arr){
            str.push_back(to_string(a));
        }
        
        sort(str.begin(), str.end(), cmp);
        
        string result="";
        for(string &s : str){
            result+=s;
        }
        
        if(result[0]=='0'){
            return "0";
        }
        
        return result;
        
    }
};