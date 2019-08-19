// leetcode 173.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:

    BSTIterator(TreeNode* root) {
        while(root) {
            numstk.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto tmp = numstk.top();
        numstk.pop();
        if(tmp->right) {
            auto tmp2 = tmp->right;
            numstk.push(tmp2);
            while(tmp2->left) {
                numstk.push(tmp2->left);
                tmp2 = tmp2->left;
            }
        }
        return tmp->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        // if(numstk.size())
        //     return true;
        // return false;
        return numstk.size();
    }
private:
    stack<TreeNode*> numstk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// 48ms 95.70%
// 24MB 100.00%
