class Solution {
public:
    // APPROACH - what the question ask is that after ith query what will be the sum of all even numbers inside the nums arr
    // what we will do is calculate the initial sum of the nums according to the condition then we will run a loop for queries
    // for every query we will go to nums index which is mentioned in the second column of every query. then we will check if 
    // the current number in the nums array is even we will subtract the number from our sum, then we will run the query as it is 
    // given in the question. then we will check if the new number we got at nums index is even or not. if it is we will add it
    // in nums. then we finally push the sum in answer vector.
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0)
            sum += nums[i];
        }
        // cout<<sum;
        for(int i=0; i<queries.size(); i++){
            if(nums[queries[i][1]]%2==0)    sum -= nums[queries[i][1]];
            
            nums[queries[i][1]] += queries[i][0];
            
            if(nums[queries[i][1]]%2==0)    sum += nums[queries[i][1]];
            
            ans.push_back(sum);
        }
        return ans;
    }
};