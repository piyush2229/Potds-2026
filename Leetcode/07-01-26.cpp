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
    long long totalsum=0,ans=0;
    int mod=1e9+7;
    long long allsum(TreeNode*node){
        if(!node) return 0;
        return node->val+allsum(node->left)+allsum(node->right);
    }
    long long dfs(TreeNode* node){
        if(!node) return 0;
        long long currsum=node->val+dfs(node->left)+dfs(node->right);
        long long product=currsum*(totalsum-currsum);
        ans=max(ans,product);
        return ans;
    }
    int maxProduct(TreeNode* root) {
        totalsum=allsum(root);
        dfs(root);
        return ans%mod;
    }
};
// calculate total sum of tree
// use dfs to calculate sum of each subtree
// for each subtree, calculate product of sum of that subtree and sum of rest of tree
// update maximum product found
// return maximum product modulo 1e9+7