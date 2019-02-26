class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int row = dungeon.length;
        int col = dungeon[0].length;
        int[][] dis = new int[row+1][col+1];
        for (int i = 0; i <= row; i++) 
            Arrays.fill(dis[i], Integer.MAX_VALUE);
        dis[row][col-1] = 1;
        dis[row-1][col] = 1;
        for (int i = row-1; i >=0; i--)
            for (int j = col-1; j >= 0; j--){
                dis[i][j] = Math.max(1, Math.min(dis[i+1][j], dis[i][j+1]) - dungeon[i][j]);
                //System.out.println("dis "+i+" "+j+"="+dis[i][j]);
            }
                
                                     
        return dis[0][0];
    }
}
