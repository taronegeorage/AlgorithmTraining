public class Solution {
    /**
     * @param A: An integer array
     * @return: An integer
     */
    public int stoneGame(int[] A) {
        // write your code here
        if(A.length == 0)
            return 0;
        int[][] dp = new int[A.length][A.length];
        for (int i = 0; i < A.length; i++) 
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        boolean[][] visited = new boolean[A.length][A.length];
        for (int i = 0; i < A.length; i++) 
            Arrays.fill(visited[i], false);
        int[][] presum = new int[A.length][A.length];
        
        for (int i = 0; i < A.length; i++){
            presum[i][i] = A[i];
            for (int j = i + 1; j < A.length; j++)
                presum[i][j] = presum[i][j-1] + A[j];
        }
        
        doMerge(dp, presum, visited, A, 0, A.length-1);
        return dp[0][A.length-1];
        
    }
    
    public void doMerge(int[][] dp, int[][] presum, boolean[][] visited, int[] A, int start, int end){
        if (visited[start][end] || start > end)
            return;
        visited[start][end] = true;
        if(start == end)
            dp[start][end] = 0;
        else{
            for (int i = start; i < end; i++) {
                doMerge(dp, presum, visited, A, start, i);
                doMerge(dp, presum, visited, A, i+1, end);
                dp[start][end] = Math.min(dp[start][end], presum[start][end] + dp[start][i] + dp[i+1][end]);
            }
        }
    }
}
