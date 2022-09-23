class Solution {
public:
    //ALGO - break the problem in sub-problems, for any index you have to check min((above cell + curr cell), (left cell + curr cell))
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>>dp()
        for(int i=1; i<grid[0].size();i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i=1; i<grid.size();i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1; i<grid.size(); i++){
            for(int j=1; j<grid[0].size(); j++){
                grid[i][j] = min( (grid[i-1][j]+grid[i][j]), (grid[i][j-1]+grid[i][j]) );
            }
        }
        return grid[m-1][n-1];
    }
};