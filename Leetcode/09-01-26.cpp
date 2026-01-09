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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root->left && !root->right) return root;
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        vector<TreeNode*>deepest;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<TreeNode*>temp;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                temp.push_back(node);
                q.pop();
                if(node->left){
                    parent[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right]=node;
                    q.push(node->right);
                }
            }
            deepest=temp;
        }
        unordered_set<TreeNode*>s(deepest.begin(),deepest.end());
        while(s.size()>1){
            unordered_set<TreeNode*>next;
            for(auto node:s){
                next.insert(parent[node]);
            }
            s=next;
        }
        return *s.begin();

    }
};
// find the subtree containing all deepest nodes in a binary tree
// use bfs to find deepest nodes and store their parents
// use a set to track current deepest nodes
// iteratively move up to their parents until only one node remains in the set
// return that node as the subtree root
