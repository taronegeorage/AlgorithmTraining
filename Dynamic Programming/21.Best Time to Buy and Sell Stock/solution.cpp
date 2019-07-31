// leetcode 121.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int ans = 0, cur = -prices[0];
        for(auto& val : prices) {
            cur = max(cur, -val);
            if(val+cur > ans)
                ans = val + cur;
        }
        return ans;
    }
};

// 12ms 23.93%
// 9.4MB 92.84%
