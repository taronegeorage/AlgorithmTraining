class Solution {
    public int maxCoins(int[] nums) {
        int len = nums.length;
        int[] newnums = new int[len + 2];
        newnums[0] = 1;
        for (int i = 1; i <= len; i++)
            newnums[i] = nums[i-1];
        newnums[len+1] = 1;
        
        int[][] c = new int[len+2][len+2];
        for(int l = 1; l <= len; ++l){
            for(int i = 1; i <= len-l+1; ++i){
                int j = i+l-1;
                for(int k = i; k <= j; ++k){
                    c[i][j] = Math.max(c[i][j], c[i][k-1] + newnums[i-1]*newnums[k]*newnums[j+1]+c[k+1][j]);
                }
            }
        }
        return c[1][len];
    }
}
