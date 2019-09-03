// leetcode 90.
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int>& nums, int u) {
        if(u == nums.size()) {
            ans.push_back(cur);
            return;
        }
        int k = 0;
        while(u+k < nums.size() && nums[u+k]==nums[u]) k++;

        for(int i = 0; i <= k; i++) {
            dfs(nums, u+k);
            cur.push_back(nums[u]);
            cout << nums[u] << " ";
        }
        for(int i = 0; i <= k; i++)
            cur.pop_back();
    }
};

// 8ms 84.21%
// 9.6MB 45.45%
