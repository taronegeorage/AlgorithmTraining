// leetcode 17.
class Solution {
public:
    string chars[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> ans(1,"");
        for(auto ch : digits) {
            vector<string> now;
            for(auto c : chars[ch-'2']) 
                for(auto s : ans)
                    now.push_back(s+c);
            ans = now;
        }

        return ans;
    }
};

// 0ms 100%
// 8.5MB 92.86%
