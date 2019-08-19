// leetcode 124.
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans, left+root->val+right);
        return max(0, root->val+max(left, right));
    }
};

// 32ms 56.06%
// 24.6MB 66.67%
