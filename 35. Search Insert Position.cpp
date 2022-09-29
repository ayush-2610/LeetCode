class Solution {
// Algo - remember that we may or may not find the element so mid+1, mid-1
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int mid;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid]>=target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
