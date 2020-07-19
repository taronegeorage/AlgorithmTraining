//leetcode 1458.

const int N = 510;
int dp[N][N];

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                dp[i][j] = nums1[i-1]*nums2[j-1];
        }

        int ans = nums1[0] * nums2[0];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int a = nums1[i-1], b = nums2[j-1];
                if(i > 1) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j > 1) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                if(i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a*b);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
