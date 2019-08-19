// leetcode 6.
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ans;
        for(int i = 0; i < numRows; i++) {
            if(!i || i == numRows-1) {
                for(int j = i; j<s.size(); j+=2*(numRows-1))
                    ans+=s[j];
            }
            else {
                for(int j = i, k =2*(numRows-1)-i; j<s.size()||k<s.size(); j+=2*(numRows-1), k+=2*(numRows-1)) {
                    if(j < s.size()) ans+=s[j];
                    if(k < s.size()) ans+=s[k];
                }
            }
        }
        return ans;
    }
};

// 12ms 76.11%
// 10.3MB 79.63%
