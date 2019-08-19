// leetcode 101.
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
    bool dfs(TreeNode* l, TreeNode* r) {
        // if(!l && !r) return true;
        // if(!l || !r) return false;
        if(!l || !r) return !l && !r;
        // if(l->val != r->val)
        //     return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left) && l->val == r->val;
    }
    bool isSymmetric(TreeNode* root) {
        // if(!root)
        //     return true;
        // `return dfs(root->left, root->right);
        
        // auto l = root, r = root;
        // return dfs(l, r);
        
        if(!root) return true;
        stack<TreeNode*> left, right;
        auto l = root->left, r = root->right;
        while(l || r || left.size() || right.size()) {
            while(l && r) {
                left.push(l); l = l->left;
                right.push(r); r = r->right;
            }
            if(l || r) return false;
            l = left.top();
            r = right.top();
            if(l->val != r->val)
                return false;
            left.pop();
            right.pop();
            l = l->right;
            r = r->left;
        }
        return true;
    }
};
