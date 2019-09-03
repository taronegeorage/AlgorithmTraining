// leetcode 46.
class Solution {
public:
    int n;
    vector<bool> st;
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        st = vector<bool>(n);
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int u) {
        if(u == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!st[i]) {
                st[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, u+1);
                cur.pop_back();
                st[i] = false;
            }
        }
    }
};

// 12ms 66.84%
// 9.4MB 53.73%
