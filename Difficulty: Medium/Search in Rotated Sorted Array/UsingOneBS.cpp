class Solution {
  public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0,high=n-1,mid;
        
        while(low<=high){
            
            mid=(low+high)/2;
            
            if(arr[mid]==target) return mid;
            
            // Left half is sorted
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && target<arr[mid]) high=mid-1;
                else low=mid+1;
            }
            
            // Right half is sorted
            else{
                if(arr[mid]<target && target<=arr[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};