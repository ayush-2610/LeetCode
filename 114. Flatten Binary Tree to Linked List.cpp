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
    // ALGO = for every node root->right must be root->left and root->(earlier right) should be at
    // root>left's->rightmost positon (see all 5 statments in if condition for better understanding)
    // or check this link = 
    //https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/2338791/C%2B%2B-oror-EXPLAINED-oror
    TreeNode* rightmost(TreeNode* node){
        if(node->right == NULL) return node;
        return rightmost(node->right);
        
    }
    void flatten(TreeNode* root) {
        if(root==NULL) return;
     TreeNode* rghtmost;
     TreeNode* rightSubTree;
        while(root){
            if(root->left){
                rightSubTree = root->right;
                rghtmost = rightmost(root->left);
                root->right = root->left;
                rghtmost->right = rightSubTree;
                root->left = NULL;
            }
            root = root->right;
        } 
    }
};