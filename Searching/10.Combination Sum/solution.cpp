// leetcode 39.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        doCombinationSum(cur, ans, 0, target, candidates);
        return ans;
    }
    void doCombinationSum(vector<int>& cur, vector<vector<int>>& ans, int start, int left, vector<int>& candidates) {
        if(left == 0) {
            ans.push_back(cur); return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] <= left) {
                cur.push_back(candidates[i]);
                doCombinationSum(cur, ans, i, left-candidates[i], candidates);
                cur.pop_back();
            }
        }
    }
    void doCombinationSumtmp(vector<int>& cur, vector<vector<int>>& ans, int sum, int layer, vector<int>& candidates, const int target) {
        if(sum == target && cur.size() > 0) {
            ans.push_back(cur); return;
        }
        else if(layer == candidates.size()) return;
        for(int i = layer; i < candidates.size(); i++) {
            if(sum + candidates[i] > target) {
                doCombinationSumtmp(cur, ans, sum, layer+1, candidates, target);
                continue;
            }
            int time = 1;
            while(sum + time * candidates[i] <= target) {
                int k1 = time, k2 = time;
                int cost = time * candidates[i];
                sum += cost;
                while(k1--) cur.push_back(candidates[i]);
                doCombinationSumtmp(cur, ans, sum, layer+1, candidates, target);
                while(k2--) cur.pop_back();
                sum -= cost;
                time++;
            }
        }
    }
};
