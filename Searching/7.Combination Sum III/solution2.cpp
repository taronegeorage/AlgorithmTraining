class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        doCombinationSum3(cur, ans, 1, k, n);
        return ans;
    }
    void doCombinationSum3(vector<int>& cur, vector<vector<int>>& ans, int start, int k, int n) {
        if(k == 0 && n==0) {
            ans.push_back(cur); return;
        }
        if(k == 0 || n==0) return;
        for(int i = start; i <= 9; i++) {
            cur.push_back(i);
            doCombinationSum3(cur, ans, i+1, k-1, n-i);
            cur.pop_back();
        }
    }
};
