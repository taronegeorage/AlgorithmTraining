public class Solution {
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    public boolean canJump(int[] A) {
        // write your code here
        boolean[] status = new boolean[A.length];
        status[0] = true;
        
        for (int i = 1; i < A.length; i++){
            for (int j = 0; j < i; j++){
                if(status[j] == true && j + A[j] >= i){
                    status[i] = true;
                    break;
                }
            }
        }
        return status[A.length-1];
    }
}
