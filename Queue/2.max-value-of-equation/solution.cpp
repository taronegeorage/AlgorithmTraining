// leetcode 1499.
// 699ms 95.29% 89.9MB 100%
// max value in sliding window => Monotonic queue

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> q;
        int ans = INT_MIN;
        for(int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            while(q.size() && x-points[q.front()][0]>k) q.pop_front();
            if(q.size()) ans = max(ans, x+y+points[q.front()][1]-points[q.front()][0]);
            while(q.size() && points[q.back()][1]-points[q.back()][0]<=y-x) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};
