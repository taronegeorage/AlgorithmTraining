public class Solution {
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    public int minPathSum(int[][] grid) {
        // write your code here
        int row = grid.length;
        int col = grid[0].length;
        int[][] states = new int[row][col];
        int sum = 0;
        
        for (int j = 0; j < col; ++j){
            sum += grid[0][j];
            states[0][j] = sum;
        }
        sum = 0;
        for (int i = 0; i < row; ++i){
            sum += grid[i][0];
            states[i][0] = sum;
        }
        if (row == 1 || col == 1){
            return states[row-1][col-1];
        }
        for (int i = 1; i < row; ++i){
            for (int j = 1; j < col; ++j){
                states[i][j] = grid[i][j] + Math.min(states[i][j-1], states[i-1][j]);
            }
        }
        return states[row-1][col-1];
    }
}
