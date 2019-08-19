// leetcode 543.
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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if(!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans, left+right);
        return max(left+1, right+1);
    }
};

// 12ms 69.56%
// 19.7MB 92.59%
