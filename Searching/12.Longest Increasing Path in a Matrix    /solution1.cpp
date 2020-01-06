class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if(row==0) return 0;
        col = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) 
                ans = max(ans, dfs(i, j, matrix));
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if(lookup[i][j]) return lookup[i][j];
        int ans = 1;
        int direct[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for(int id = 0; id < 4; id++) {
            int tmpi = i + direct[id][0];
            int tmpj = j + direct[id][1];
            if(tmpi>=0 && tmpj>=0 && tmpi<row && tmpj<col && matrix[tmpi][tmpj] > matrix[i][j])
                ans = max(ans, 1+dfs(tmpi, tmpj, matrix));
        }
        lookup[i][j] = max(ans, lookup[i][j]);
        return lookup[i][j];
    }
private:
    int lookup[200][200], row, col;
};
