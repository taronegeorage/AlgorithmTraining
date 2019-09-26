class Solution {
public:
    int minimumTotal1(vector<vector<int>>& triangle) {
        vector<int> ans = triangle[triangle.size()-1];
        for(int i = triangle.size()-2; i>=0; i--)
            for(int j = 0; j < triangle[i].size(); j++)
                ans[j] = triangle[i][j] + min(ans[j], ans[j+1]);
        return ans[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++) 
            for(int j = 0; j <= i; j++) {
                dp[i&1][j] = INT_MAX;
                if(j > 0) dp[i&1][j] = min(dp[i&1][j], dp[i-1 & 1][j-1]+triangle[i][j]);
                if(j < i) dp[i&1][j] = min(dp[i&1][j], dp[i-1 & 1][j]+triangle[i][j]);
            }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) ans = min(ans, dp[n-1 & 1][i]);
        return ans;
    }
};
