class Solution {
  public:
    bool twoSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int l=0,h=nums.size()-1;
        
        while(l<h){
            if(nums[l]+nums[h]==target)
                return true;
            else if(nums[l]+nums[h]>target)
                h--;
            else if(nums[l]+nums[h]<target)
                l++;
        }
        return false;
    }
};