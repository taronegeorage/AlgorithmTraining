class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1, false);
        unordered_set<string> dicts(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i <= s.length(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && dicts.find(s.substr(j, i-j)) != dicts.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
