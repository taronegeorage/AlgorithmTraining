// leetcode 94.

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        auto p = root;
        while(p || s.size()) {
            while(p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            ans.emplace_back(p->val);
            p = p->right;
        }
    return ans;
    }
};

// 4ms 59.67%
// 9.1MB 97%
