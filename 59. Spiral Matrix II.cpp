class Solution {
public:
    // ALgo = this is all visulisation declare an iterator integer i and an integer j. alot j  w.r.t  i and iterate over 
    // matrix;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int num = 1, i=0,j;
        while(num <= n*n){
            j = i;
            while(j<n-i){
                ans[i][j++] = num++;
            }
            j=i+1;
            while(j<n-i){
                ans[j++][n-i-1] = num++;
            }
            j = n-i-2;
            while(j > i){
                ans[n-i-1][j--] = num++;
            }
            j = n - i - 1;
            while(j > i){
                ans[j--][i] = num++;
            }
            i++;
        }
        return ans;
    }
};