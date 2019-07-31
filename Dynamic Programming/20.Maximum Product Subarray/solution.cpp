// leetcode 152.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int dp[2][2], ans;
        dp[0][1] = dp[0][0] = ans = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            int x = i % 2;
            int y = (i-1) % 2;
            dp[x][0] = max(max(dp[y][0]*nums[i], dp[y][1]*nums[i]), nums[i]);
            dp[x][1] = min(min(dp[y][0]*nums[i], dp[y][1]*nums[i]), nums[i]);
            ans = max(ans, dp[x][0]);
        }
        
        return ans;
    }
};

// 4ms 91.57%
// 8.8MB 100%
