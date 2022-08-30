class Solution {
public:
    //Algo - If you see clearly first entire column is converted into row and then it is reversed.
    // so just do that swap elements of row and column and then reverse the rows, you will get answer
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
         for(int i=0; i<matrix.size(); i++){
             reverse(matrix[i].begin(), matrix[i].end());
         }
    }
};