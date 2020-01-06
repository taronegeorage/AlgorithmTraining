// leetcode 47.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        bool visited[nums.size()];
        for(int i = 0; i < nums.size(); i++) visited[i] = false;
        doPermute(cur, ans, visited, nums);
        return ans;
    }
    void doPermute(vector<int>& cur, vector<vector<int>>& ans, bool* visited, vector<int>& nums) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur); return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(visited[i]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            doPermute(cur, ans, visited, nums);
            cur.pop_back();
            visited[i] = false;
        }
        
    }
};

