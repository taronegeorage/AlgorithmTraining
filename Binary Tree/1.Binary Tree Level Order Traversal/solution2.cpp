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
        help(root, 0);
        return ans;
    }
    
    void help(TreeNode* root, int level){
        if(root == NULL)
            return;
        if(level >= max){
            max++;
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        help(root->left, level+1);
        help(root->right, level+1);
    }
private:
    vector<vector<int> > ans;
    int max = 0;
};

// 8ms 77.36%
// 14.9MB 16.05%
