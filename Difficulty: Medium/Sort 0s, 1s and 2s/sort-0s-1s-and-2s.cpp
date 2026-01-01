class Solution {
  public:
    void sort012(vector<int>& arr) {
        int count0=0,count1=0,count2=0;
        
        for(int ele : arr){
            if(ele==0) count0++;
            else if(ele==1) count1++;
            else count2++;
        }
        
        for(int i=0;i<arr.size();i++){
            if(count0) arr[i]=0,count0--;
            else if(count1) arr[i]=1,count1--;
            else if(count2) arr[i]=2,count2--;
        }
        
    }
};