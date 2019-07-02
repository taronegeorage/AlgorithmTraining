// leetcode 104.
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

// 12ms 76.54%
// 19.4MB 62.91%
//
//


int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int max = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            max++;
        }
        return max;
    }

// 16ms 56.25%
// 19.1MB 92.70%
