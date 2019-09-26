class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
        sort(dp.begin(), dp.end());
        return dp.back();
        
    }
    int maxSubArray1(vector<int>& nums) {
        int ans = INT_MIN, last = 0;
        for(auto& num : nums) {
            int cur = max(0, last) + num;
            // ans = max(ans, cur);
            if(cur > ans) ans = cur;
            last = cur;
        }
        return ans;
    }
};
