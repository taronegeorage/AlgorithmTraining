class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        s = " "+s;
        boolean dp[] = new boolean[s.length()+1];
        dp[0] = true;
        for(int i = 1; i < s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j]){
                    String str = s.substring(j+1, i+1);
                    if(wordDict.contains(str)){
                        System.out.println(str);
                        dp[i] = true;
                        
                        break;
                    }
                        //System.out.println(str);

                        
                    
                }
            }
        }

        return dp[s.length()-1];
    }
}
