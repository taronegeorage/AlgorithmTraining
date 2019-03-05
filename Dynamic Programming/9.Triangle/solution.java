class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {

        int[] dp = new int[triangle.size()+1];
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++){
                dp[j] = Math.min(dp[j],dp[j+1]) + triangle.get(i).get(j);
            }
        }
        /*
        for (int i = 1; i < triangle.size(); i++){
            for(int j = triangle.get(i).size()-1; j >= 0; j--){
                if (j == i)
                    dp[j] = dp[j-1] + triangle.get(i).get(j);
                else if(j == 0)
                    dp[0] = dp[0] + triangle.get(i).get(0);
                dp[j] = Math.min(dp[j], dp[j-1]) + triangle.get(i).get(j);
            }
        }
        */
        return dp[0];
    }
}
