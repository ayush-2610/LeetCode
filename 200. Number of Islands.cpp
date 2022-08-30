class Solution {
public:
    // Algo - make a helper function which checks for the neighbouring lands by calling on four different sides
    // no in main function call a for loop for the matrix once we get a land i.e '1' we call helper function 
    // while traversing through if we get a land we mark it as '2' so in this way when we call for one
    // '1' we traverse through all the lands connected to that '1' via recursion and hence the whole island
    // if i completed one call this means i get one complete island so i increase my ans by 1;
    void helper(vector<vector<char>>& grid, int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return;
        if(grid[i][j]=='0'||grid[i][j]=='2')
            return;
        grid[i][j]='2';
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
         for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    helper(grid, i, j);
                    ++ans;
                } 
            }
        }
        return ans;
    }
};