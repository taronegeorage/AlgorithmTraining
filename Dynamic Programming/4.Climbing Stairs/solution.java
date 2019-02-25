public class Solution {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        // write your code here
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int state[] = new int[n];
        state[0] = 1;
        state[1] = 2;
        for (int i = 2; i < n; i++)
            state[i] = state[i - 1] + state[i - 2];
        return state[n-1];
    }
}
