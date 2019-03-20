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
};
