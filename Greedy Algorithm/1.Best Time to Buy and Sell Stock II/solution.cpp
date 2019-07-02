// leetcode 122.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int ans = 0;
        for(int i = 0; i < size-1; i++){
            if(prices[i+1]>prices[i])
                ans += prices[i+1]-prices[i];
        }
        return ans;
    }
}

//4ms 99.08%
//9.4MB 83.65%
