// leetcode 40.
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        doCombinationSum(cur, ans, 0, target, visited, candidates);
        return ans;
    }
    void doCombinationSum(vector<int>& cur, vector<vector<int>>& ans, int start, int left, vector<bool>& visited, vector<int>& candidates) {
        if(left == 0) {
            ans.push_back(cur); return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(i != 0 && candidates[i] == candidates[i-1] && !visited[i-1]) continue;
            if(candidates[i] <= left) {
                cur.push_back(candidates[i]);
                visited[i] = true;
                doCombinationSum(cur, ans, i+1, left-candidates[i], visited, candidates);
                visited[i] = false;
                cur.pop_back();
            }
        }
    }
};


    
