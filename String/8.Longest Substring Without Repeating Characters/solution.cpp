// leetcodee 3.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> store;
        int ans = 0;
        for(int i = 0, j = 0; i < s.size(); i++) {
            store[s[i]]++;
            while(store[s[i]]>1) store[s[j++]]--;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

// 20ms 60.05%
// 11MB 52.24%
