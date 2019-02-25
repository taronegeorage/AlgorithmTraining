public class Solution {
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    public boolean canJump(int[] A) {
        // write your code here
        int maxReach = 0;
        for (int i = 0; i < A.length; i++){
            if (i <= maxReach)
                maxReach = Math.max(maxReach, i + A[i]);
            if (maxReach >= A.length-1)
                return true;
        }
        return false;
    }
}
