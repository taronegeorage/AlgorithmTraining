
//5 ms, faster than 100.00% of Java online submissions 
class Solution {
    public int maxSubArray(int[] nums) {

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int max = nums[0];
        for (int i = 1; i < nums.length; i++){
            dp[i] = Math.max(nums[i], dp[i-1]+nums[i]);
            if(max < dp[i])
                max = dp[i];
        }
        return max;
    }
}

/*
    // time : O(n) space : O(n);
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.length; i++) {
            dp[i] = nums[i] + (dp[i - 1] < 0 ? 0 : dp[i - 1]);
            res = Math.max(res, dp[i]);
        }
        return res;
    }

    // time : O(n) space : O(1);
    public int maxSubArray2(int[] nums) {
        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            sum = Math.max(nums[i], sum + nums[i]);
            res = Math.max(res, sum);
        }
        return res;
    }
*/


/*
    public int maxSubArray(int[] nums) {
        int[] presum = new int[nums.length+1];
        int sum = 0;
        int max_val = nums[0];
        for (int i = 1; i <= nums.length; i++){
            sum += nums[i-1];
            presum[i] = sum;
            for (int j = i-1; j >= 0; j--){
                int val = presum[i] - presum[j];
                if (val > max_val)
                    max_val = val;
            }
        }
        return max_val;
    }
*/

