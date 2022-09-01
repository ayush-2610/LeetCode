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
    // Algo is simple just traverse through the tree if we get a node greater than current maximum
    // then we update our ans by 1 and also update our current max. return ans at last
    int helper(TreeNode* root, int max){
        int ans = 0;
        if(root->val>=max){
            max = root->val;
            ans++;
        }
        if(root->left){
             ans += helper(root->left,max);
        }
        if(root->right){
            ans += helper(root->right,max);
        }
        return ans;
    }
    int goodNodes(TreeNode* root) {
        int max = root->val;
        return helper(root,max);
    }
};