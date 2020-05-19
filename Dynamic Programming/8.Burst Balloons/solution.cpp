class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newnum(n+2, 1);
        for(int i = 1; i <= n; i++) newnum[i] = nums[i-1];
        
        vector<vector<int> > c(n+2, vector<int>(n+2, 0));
        for(int l = 1; l <= n; ++l) 
            for(int i = 1; i <= n-l+1; ++i) {
                int j = i+l-1;
                for(int k = i; k <= j; ++k) 
                    c[i][j] = max(c[i][j], c[i][k-1]+newnum[i-1]*newnum[k]*newnum[j+1]+c[k+1][j]);
            }
        return c[1][n];
    }

};
