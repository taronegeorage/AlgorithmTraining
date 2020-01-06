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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(isValidBST(root->left)) {
            if(last < root->val) {
                last = root->val;
                return isValidBST(root->right);
            }
        }
        return false;
    } 

private:
    long last =  LONG_MIN;
};
