class Solution {
public:
    // ALGO = what the question asks is to add the max of ((front element of nums * front element of multiplier),(last element 
    // of nums * front element of multiplier)) and remove the element form the array. we cannot practically remove the element
    // so we play with indices.  in1 = index of nums array, in 2 = index of multiplier array, and to take end element of nums
    // we will just do (n-1) - (in2-in1) i.e difference between in1 ans  in2 will tell us how many elements from last have been 
    // taken till now.
    // also we have taken INT_MIN as default in dp beacuse array elements are integers i.e -ve and +ve both.
    // WORKING OF RECURSION = for the current element once (we take it and multiply it with multiplier index) or ( we dont take id
    // and go for the last element and multiply it with multiplier index)
    // then we save max (for that element in dp)
    vector<vector<int>>dp;
    int solve(vector<int>& nums, vector<int>& multipliers, int in1, int in2, int n){
        if(in2==multipliers.size()) return 0;
         
        if(dp[in1][in2]!=INT_MIN) return dp[in1][in2];
        
        int ansL = solve(nums,multipliers,in1+1,in2+1,n) + nums[in1]*multipliers[in2];
        int ansR = solve(nums,multipliers,in1,in2+1,n) + nums[(n-1)-(in2-in1)]*multipliers[in2];
        
        return dp[in1][in2] = max(ansL,ansR);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m+1,vector<int>(m+1, INT_MIN));
        return solve(nums,multipliers,0,0,n);
    }
};