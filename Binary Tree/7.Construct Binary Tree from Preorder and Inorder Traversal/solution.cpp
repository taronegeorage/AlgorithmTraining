// leetcode 105.

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
    unordered_map<int, int> pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        for(int i = 0; i < size; i++) pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, size-1, 0, size-1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if(pl > pr) return NULL;
        int val = preorder[pl];
        auto head = new TreeNode(val);

        int inorder_idx = pos[val];
        int len = inorder_idx - il;
        head->left = dfs(preorder, inorder, pl+1, pl+len, il, inorder_idx-1);
        head->right = dfs(preorder, inorder, pl+len+1, pr, inorder_idx+1, ir);
        return head;
    }
};

// 12ms 93.02%
// 17.4MB 42.86%
