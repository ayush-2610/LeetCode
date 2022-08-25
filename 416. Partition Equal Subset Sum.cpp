class Solution {
public:
    // Algo - first calculate sum of all elements. do sum/2 if it is odd return false else check if 
    // are there elements present whose Sum is exactly equal to sum/2
    // if present return true else false
    bool subset(vector<int>&nums,int sum){
        int dp[nums.size()+1][sum+1];
        for(int i=0; i<=nums.size();i++){
            for(int j=0; j<=sum;j++){
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
         for(int i=1; i<=nums.size();i++){
            for(int j=1; j<=sum;j++){
                if(j<nums[i-1])
                    dp[i][j] = dp[i-1][j]; // if req sum is less than curr element skip that element
                else{
                    dp[i][j] = (dp[i-1][j]) || (dp[i-1][j-nums[i-1]]);// skip or take whichever helps getting that sum.
                }
            }
         }
        return dp[nums.size()][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%2!=0)
            return false;
        else
            return subset(nums,sum/2);
    }
};