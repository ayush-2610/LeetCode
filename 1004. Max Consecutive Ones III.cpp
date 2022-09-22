class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int i=0,j=0;
         int temp = 0;
         int maxi = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0) temp++;
            while(temp>k){
                if(nums[i]==0) temp--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
            }
        return maxi;     
    }
};