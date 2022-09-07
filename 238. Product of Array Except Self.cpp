class Solution {
public:
    // ALGO - this question is easy first think of brute force then think how to get all elemnts product
    // except self without dividing total product. one way is multiply all elements before and all after 
    // current element;
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        // vector<int>pre(n),suff(n);
        int productPre = 1;
        for(int i=0; i<n; i++){
            ans[i] = productPre; 
            productPre *= nums[i];
        }
        int productSuff = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= productSuff;
            productSuff *= nums[i];
        }
        return ans;

    }
};