class Solution {
    HashMap<Integer, ArrayList<String>> data = new HashMap<Integer, ArrayList<String>>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s, wordDict, 0);
    }
    public List<String> dfs(String s, List<String> wordDict, int start){
        if(data.containsKey(start))
            return data.get(start);
        ArrayList<String> res = new ArrayList<>();
        if(start == s.length())
            res.add("");
        for(int end = start+1; end <= s.length(); end++){
            if(wordDict.contains(s.substring(start, end))){
                List<String> list = dfs(s, wordDict, end);
                for(String temp : list)
                    res.add(s.substring(start, end)+(temp.equals("") ? "" : " ") + temp);
            }
        }
        data.put(start, res);
        return res;
    } 
}
