// 787.
class Solution {
public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        constexpr int inf = 1e9;
        vector<int> dp(n, inf);
        dp[src] = 0;
        
        for(int i = 0; i <= K; i++){
            vector<int> tmp(dp);
            for(const auto& p : flights){
                tmp[p[1]] = min(tmp[p[1]], dp[p[0]]+p[2]);
            }
            dp.swap(tmp);
        }
        
        return dp[dst] >= inf ? -1 : dp[dst];
        
    }
    int findCheapestPrice_1(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        constexpr int inf = 1e9;
        vector<vector<int>> dp(K+2, vector<int>(n, inf));
        dp[0][src] = 0;
        for(int i = 1; i <= K+1; i++){
            dp[i][src] = 0;
            for(const auto& p : flights){
                cout << p[0] << " to " << p[1] << " " << p[2] << endl;
                cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
                dp[i][p[1]] = min(dp[i][p[1]], dp[i-1][p[0]]+p[2]);
            }
                
        }
        
        return dp[K+1][dst] >= inf ? -1 : dp[K+1][dst];
        
    }
    int findCheapestPrice_xxx(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int num = flights.size();
        vector<int> dp(num, -1);
        vector<int> visited(num, 1);
        
        for(int i = 0; i < num; i++)
            dp[flights[i][1]] = flights[i][2];
        visited[src] = 0;
            
        if (K < 1)
            return dp[dst];
        for(int i = 1; i <= K; i++){
            for(int j = 0; j < num; j++){
                if(dp[j] != -1 && visited[j]){
                    for(int m = 0; m < num; m++){
                        if(flights[m][0] == j && dp[flights[m][1]] == -1)
                            dp[flights[m][1]] = dp[j]+flights[m][2];
                        else if(flights[m][0] == j && dp[j]+flights[m][2] < dp[flights[m][1]])
                            dp[flights[m][1]] = dp[j]+flights[m][2];
                    }
                    visited[j] == 0;
                }
            }
        }
        
        return dp[dst];
        
    }
};
