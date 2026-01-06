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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int maxi=INT_MIN;
        int ans=1;
        int level=1;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            int currsum=0;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                currsum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(maxi<currsum){
                ans=level;
                maxi=currsum;
            }
            level++;
        }
        return ans;
    }
};

//classic bfs level order traversal
//keep track of sum at each level
//update maximum sum and corresponding level
//return level with maximum sum