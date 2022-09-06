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
    // ALGO = traverse the whole tree while maintaining priority queue's top element smaller than the element
    // we are currently on and also maintaining the size of priority queue = k at last we get kth smallest at 
    // top.
    int helper(TreeNode* root, int k, priority_queue<int>&pq){
        if(root==NULL) return 0;
        if(pq.size()<k) pq.push(root->val);
        else if(pq.size()>=k&&root->val<pq.top()){
            pq.pop();
            pq.push(root->val);
        }
        helper(root->left,k,pq);
        helper(root->right,k,pq);
        return pq.top();
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>pq;
        return helper(root,k,pq);
    }
}; 