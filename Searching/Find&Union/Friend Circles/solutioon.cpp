// leetcode 547.
class Solution {
public:
    vector<int> p;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int findCircleNum(vector<vector<int>>& M) {
        int num = M.size();
        for(int i = 0; i < num; i++) p.push_back(i);
        int ans = num;
        for(int i = 0; i < num; i++)
            for(int j = 0; j < i; j++) {
                if(M[i][j] == 0) continue;
                else if(find(i) != find(j)) {
                    p[find(i)] = find(j);
                    ans--;
                }
            }
        return ans;
    }
};

// 16ms 97.11%
// 10.8MB 100%
