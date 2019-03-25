// 688.
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp0(N, vector<double>(N, 0));
        dp0[r][c] = 1;
        int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                         {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
        for(int k = 0; k < K; k++){
            vector<vector<double>> dp1(N, vector<double>(N, 0));
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    for(int m = 0; m < 8; m++){
                        int x = j + dir[m][0];
                        int y = i + dir[m][1];
                        if(x < 0 || y < 0 || x >= N || y >= N) continue;
                        dp1[y][x] += dp0[i][j];
                    }
                    
                }
            }
            swap(dp0, dp1);
        }
        
        double t = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                t += dp0[i][j];
        return t/pow(8, K);
    }
};
