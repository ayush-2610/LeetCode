/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // Algo = general bfs. at every node enter new queue members while pushing the node value in our current 
    // level of answer; 
    vector<vector<int>> levelOrder(Node* root) {
            vector<vector<int>>ans;
            if(root== NULL) return ans;
            queue<Node*>q;
            q.push(root);
            while(!q.empty()){
                vector<int>curr; // a new level
                int n = q.size();// how many elements are going to be there in new level = size of queue at that point of time

                for(int i=0; i<n;i++){
                    Node* temp = q.front();
                    q.pop();
                    curr.push_back(temp->val); // pushing values to our answer
                    for(auto it: temp->children){
                        q.push(it);
                    }
                }
                ans.push_back(curr);
            }
            return ans;
    }
};