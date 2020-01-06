class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
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
            if(visited[i]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            doPermute(cur, ans, visited, nums);
            cur.pop_back();
            visited[i] = false;
        }
        
    }
};
