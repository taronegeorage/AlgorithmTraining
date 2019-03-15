ass Solution {
public:
    // int uniquePaths(int m, int n) {
    //     int count = m + n - 2;
    //     int k = m - 1;
    //     double ans = 1;
    //     for(int i = 1; i <= k; i++)
    //         ans = ans * (count - k + 1) / i;
    //     return (int)ans;
    // }
    int uniquePaths2(int m, int n) {
        auto dp_ = vector<vector<int>> (n+1, vector<int>(m+1, 0));
        dp_ [0][1] = 1;
        for(int j = 1; j <= m; j++)
            for(int i = 1; i <= n; i++)
                dp_[i][j] = dp_[i-1][j] + dp_[i][j-1];
        return dp_[n][m];
    }
    int uniquePaths1(int m, int n) {
        if (m < 0 || n < 0) return 0;
        if(m == 1 || n == 1) return 1;
        if(dp[m][n] > 0) return dp[m][n];
        int left = uniquePaths(m - 1, n);
        int up = uniquePaths(m, n - 1);
        dp[m][n] = left + up;
        return dp[m][n];
    }
private:
    unordered_map<int, unordered_map<int, int>> dp;
};
