// leetcode 5.
class Solution {
public:
    // 28ms 63.50%
    // 16.4MB 35.17%
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++) {
            for(int j = i, k = i; j >= 0 && k < s.size() && s[j]==s[k]; j--, k++) {
                if(ans.size() < k - j + 1)
                    ans = s.substr(j, k-j+1);
            }
            for(int j = i, k = i+1; j >= 0 && k < s.size() && s[j]==s[k]; j--, k++) {
                if(ans.size() < k - j + 1)
                    ans = s.substr(j, k-j+1);
            }
        }
        return ans;
    }
    // 364ms 9.92%
    // 8.9MB 66.89%
    string longestPalindrome2(string s) {
        if(s.size() <= 1)
            return s;
        int len = 1;
        //string ans = to_string(s[0];
        stringstream ans;
        ans << s[0];
        for(int i = 0; i < s.size(); i++) {
            for(int j = s.size()-1; j > i; j--) {
                int st = i, end = j;
                while(st <= end && s[st] == s[end]) {
                    st++;
                    end--;
                }
                if(st > end && j-i+1 > len) {
                    ans.str("");
                    // ans = s.substr(i, l+1);
                    ans << s.substr(i, j-i+1);
                    len = j-i+1;
                    // cout << ans.str() << endl;
                }
            }
            if(len >= s.size()-i)
                break;
        }
        return ans.str();
    }
};
