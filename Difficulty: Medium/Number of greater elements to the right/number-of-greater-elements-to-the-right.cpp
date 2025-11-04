
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        vector<int> ans;
        for(int i=0;i<indices.size();i++){ 
            
            int ele=arr[indices[i]];
            int count=0;
            
            for(int j=indices[i]+1;j<arr.size();j++){
                if(arr[j]>ele) count++;
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};