// leetcode 221.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j]=='1' ? 1 : 0;
                if(i&&j&&matrix[i][j]=='1')
                    dp[i][j] = 1+min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
    int maximalSquare1(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dp[i][j] = matrix[i][j] == '1' ? (j==0?1:dp[i][j-1]+1) : 0;

        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = n-1; j >= 0; --j) {
                int len = INT_MAX;
                for(int k = i; k < m; ++k) {
                    len = min(len, dp[k][j]);
                    if(!len) break;
                    int size = min(len, k-i+1);
                    ans = max(ans, size*size);
                }
            }
        }
        return ans;
    }
};
