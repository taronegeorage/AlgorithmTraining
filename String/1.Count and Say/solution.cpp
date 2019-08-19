// leetcode 38.
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        
        for(int i = 0; i < n-1; i++) {
            stringstream ss;
            for(int j = 0; j < s.size(); j++) {
                int k = j;
                while(k < s.size() && s[k] == s[j]) {
                    k++;
                }
                ss << k-j << s[j];
                j = k-1;
            }
            s = ss.str();
        }
        return s;
    }
};
