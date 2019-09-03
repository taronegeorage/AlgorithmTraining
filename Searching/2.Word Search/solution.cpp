// leetcode 79.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // if(board.empty()||board[0].empty()) return false;
        row = board.size();
        col = board[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(dfs(board, i, j, word, 0))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int u) {
        if(board[i][j] != word[u]) return false;
        if(u == word.size()-1) return true;
        board[i][j] = '.';
        for(int idx = 0; idx < 4; idx++) {
            int a = i + dx[idx], b = j + dy[idx];
            if(a >= 0 && a < row && b >= 0 && b < col) 
                if(dfs(board, a, b, word, u+1)) 
                    return true;
        }
        board[i][j] = word[u];
        return false;
    }
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int row, col;
};

// 104ms 47.37%
// 37MB 50%
