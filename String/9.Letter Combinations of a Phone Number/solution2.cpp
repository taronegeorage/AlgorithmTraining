class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        doCombination("", ans, digits);
        return ans;
    }
    void doCombination(string cur, vector<string>& ans, const string digits) {
        if(cur.size() == digits.size()){
            ans.push_back(cur);
            return;
        }
        int curDigits = digits[cur.size()]-'0';
        string data = KEYS[curDigits];
        for(auto& ch : data) {
            //doCombination(cur+ch, ans, digits);
            cur.push_back(ch);
            doCombination(cur, ans, digits);
            cur.pop_back();
        }
        
    }
private:
    string KEYS[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

// 4ms 8.6MB
// 0ms 8.3MB
