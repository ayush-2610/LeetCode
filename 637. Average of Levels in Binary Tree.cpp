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
    // Algo - Do by using bfs search 
    // traverse the full breadth at every level take its avg and insert in ans vector
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
		q.push(root);
		vector<double> ans;

		while(!q.empty()){
			int sz = q.size();
			double rowVal = 0;
			for(int i = 0; i < sz; i++){
				auto curr = q.front();
				q.pop();
				rowVal += curr->val;
				if(curr->left)q.push(curr->left);
				if(curr->right)q.push(curr->right);
			}
			double val = rowVal / sz;
			ans.push_back(val);
		}

		return ans;
    }
};