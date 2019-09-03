// leetcode 216.
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
    
    void dfs(int start, int num, int sum) {
        if(!num) {
            if(!sum) ans.push_back(cur);
            return;
        }
        // i <= 9
        // 10 - num >= i
        for(int i = start; i <= 10-num; i++) {
            cur.push_back(i);
            // dfs(start+1, num-1, sum-i); ke chong fu
            dfs(i+1, num-1, sum-i);
            cur.pop_back();
        }
    }
};

// 0ms 100%
// 8.7MB 72.22%
