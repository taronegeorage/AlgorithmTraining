// leetcode 52.

class Solution {
public:
    int ans, num;
    unordered_set<int> col, left, right;
    int totalNQueens(int n) {
        num = n;
        dfs(n, 0);
        return ans;
    }
    void dfs(int n, int cur) {
        if(cur == n) {
            ans++;
            return;
        }
        for(int c = 0; c < n; c++) {
            if(!col.count(c) && !left.count(c+cur) && !right.count(c-cur)) {
                col.insert(c);
                left.insert(c+cur);
                right.insert(c-cur);
                dfs(n, cur+1);
                col.erase(c);
                left.erase(c+cur);
                right.erase(c-cur);
            }
        }
    }
};

// 12ms 21.21%
// 10.2MB 41.67%
