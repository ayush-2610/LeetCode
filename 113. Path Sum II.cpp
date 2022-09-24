/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //ALGO - put curr node value in a vector, subtract node value from target,check if on leaf node and targetSum == 0, if yes
    // push curr vector in ans, else call left node and right node, at last pop the curr node to check other possiblities
    vector<vector<int>>ans;
    void dfs(TreeNode* root, int targetSum, vector<int>&curr){
        if(root==NULL) return;
        curr.push_back(root->val);
        targetSum -= root->val;
        if(!(root->left)&&!(root->right)&&targetSum==0){
            ans.push_back(curr);
        }
        else{
            dfs(root->left,targetSum,curr);
            dfs(root->right,targetSum,curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr;
        dfs(root,targetSum,curr);
        return ans;
    }
};