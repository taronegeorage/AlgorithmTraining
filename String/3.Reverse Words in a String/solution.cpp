// leetcode 151.

class Solution {
public:
    string reverseWords(string s) {
        int pos = 0;
        for(int i = 0; i < s.size(); i++) {
            while(i < s.size() && s[i] == ' ') i++;
            if(i == s.size()) break;
            int j = i;
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin()+i, s.begin()+j);
            if(pos) s[pos++] = ' ';
            while(i < j)
                s[pos++] = s[i++];
        }
        s.erase(s.begin()+pos, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

// 4ms 98%
// 9.4MB 97.3%
