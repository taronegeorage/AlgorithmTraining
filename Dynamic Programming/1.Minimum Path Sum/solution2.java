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
        return minDist(row-1, col-1, states, grid);
        
    }
    
    public int minDist(int i, int j, int[][] mem, int[][] grid){
        if (i == 0 && j == 0){
            return grid[0][0];
        }
        if (mem[i][j] > 0){
            return mem[i][j];
        }
        int minLeft = Integer.MAX_VALUE;
        if(j - 1 >= 0){
            minLeft = minDist(i, j-1, mem, grid);
        }
            
        int minUp = Integer.MAX_VALUE;
        if(i - 1 >= 0){
            minUp = minDist(i-1, j, mem, grid);
        }
            
            
        int currMinDist = grid[i][j] + Math.min(minLeft, minUp);
        mem[i][j] = currMinDist;
        return currMinDist;
    }
}
