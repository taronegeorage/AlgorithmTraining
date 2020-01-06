class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int store[200];
        memset(store, -1, sizeof(int)*200);
        // vector<int> store(200, -1);
        int left = -1;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            left = max(left, store[s[i]]);
            store[s[i]] = i;
            ans = max(ans, i-left);
        }
        return ans;
    }
};

// 8ms 9.2MB
