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
    //ALGO - for a sub tree check if it is going to be eliminated or not by checking its subtree and then
    // subtree's subtree according to the conditions if a subtree satisfies condition i.e 0. we set it as NULL
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->right&&!root->left&&root->val==0) return NULL;
        return root;
    }
};