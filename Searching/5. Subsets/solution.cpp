// leetcode 78.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0; i < 1 << nums.size(); i++) {
            vector<int> now;
            for(int j = 0; j < nums.size(); j++) 
                if(i >> j & 1)
                    now.push_back(nums[j]);
            ans.push_back(now);
        }
        return ans;
    }
};

// 4ms 97.62%
// 9.2MB 61.02%
