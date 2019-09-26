// leetcode 91.
class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> ans(size+1);
        ans[0] = 1;
        for(int i = 1; i <= size; i++) {
            if(s[i-1] != '0') ans[i] += ans[i-1];
            if(i >= 2) {
                int num = (s[i-2]-'0')*10+s[i-1]-'0';
                if(num <= 26 && num >= 10) ans[i] += ans[i-2];
            }            
        }
        return ans[size];
    }
};
// 4ms 65.135
// 8.5MB 76.47%
