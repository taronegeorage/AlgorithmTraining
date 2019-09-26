// 63.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int size = obstacleGrid[0].size();
        vector<uint32_t> ans_(size, 0);
        ans_[0] = 1;
        //int *ans = new int[size] ();
        //ans[0] = 1;
        for(int i = 0; i < obstacleGrid.size(); i++){
            for(int j = 0; j < size; j++){
                //cout << i << " " << j;
                if(obstacleGrid[i][j] == 1)
                    ans_[j] = 0;
                else if(j >= 1)
                    ans_[j] += ans_[j-1];
                //cout << " " << ans_[j]  << endl;
            }
        }
        return ans_[size-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long>> f(n, vector<long>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(obstacleGrid[i][j]) continue;
                if(!i && !j) f[i][j] = 1;
                if(i > 0) f[i][j] += f[i-1][j];
                if(j > 0) f[i][j] += f[i][j-1];
            }

        return f[n-1][m-1];
    }
};
