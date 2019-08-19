// 98.Validate Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 16mss 63.47%
    // 20.6MB 92.71%
    bool help(TreeNode* root, long l, long r) {
        if(root == NULL)
            return true;
        if(root->val < l || root->val > r)
            return false;
        return help(root->left, l, root->val-1l) && help(root->right, root->val+1l, r);
    }
    // 20ms 29.45%
    // 20.6MB 82.29%
    bool dfs(TreeNode* root, long long l, long long r) {
        if(!root) return true;
        if(root->val < l || root->val > r) return false;
        return dfs(root->left, l, root->val-1ll) && dfs(root->right, root->val+1ll, r);
    }
    bool isValidBST(TreeNode* root) {
        return help(root, INT_MIN, INT_MAX);
    }
};
