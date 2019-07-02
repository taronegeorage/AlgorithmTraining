//leetcode 102.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> curLevel;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                curLevel.push_back(tmp->val);
                q.pop();
                if(tmp->left != NULL)
                    q.push(tmp->left);
                if(tmp->right != NULL)
                    q.push(tmp->right);
            }
            ans.push_back(curLevel);
        }
        return ans;
    }
};


// 4ms 96.12%
// 13.8MB 77.80%
