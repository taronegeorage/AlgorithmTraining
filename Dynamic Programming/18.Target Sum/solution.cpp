// 494.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = std::abs(S);
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S+sum)%2 != 0) return 0;
        const int target = (S+sum)/2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int num : nums)
            for(int j = target; j >= num; j--)
                dp[j] += dp[j-num];
        
        return dp[target];
    }
    
    int findTargetSumWays_2(vector<int>& nums, int S) {
        S = std::abs(S);
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S+sum)%2 != 0) return 0;
        const int target = (S+sum)/2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int num : nums){
            vector<int> tmp(dp);
            for(int j = 0; j <= target-num; j++)
                tmp[j+num] += dp[j];
            std::swap(dp, tmp);
        }
        return dp[target];
    }
    
    int findTargetSumWays_1(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < S) return 0;
        const int offset = sum;
        vector<vector<int>> ways(n+1, vector<int>(sum+offset+1, 0));
        ways[0][offset] = 1;
        for(int i = 0; i < n; i++){
            for(int j = nums[i]; j < 2*sum+1-nums[i]; j++)
                if(ways[i][j]){
                    ways[i+1][j+nums[i]] += ways[i][j];
                    ways[i+1][j-nums[i]] += ways[i][j];
                }
        }
        return ways.back()[S+offset];
    }
    
};
