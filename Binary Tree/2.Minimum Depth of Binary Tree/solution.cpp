// leetcode 111.
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        help(root, 1);
        return min;
    }
    void help(TreeNode* root, int level){
        if(root == NULL)
            return;
        else if(root->left == NULL && root->right == NULL){
            if(level < min)
                min = level;
        }
        help(root->left, level+1);
        help(root->right, level+1);
        
    }
private:
    int min = INT_MAX;
};



// 12ms 85.76%
// 19.3MB 98.10%
