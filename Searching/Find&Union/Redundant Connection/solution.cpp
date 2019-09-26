// leetcode 684.
class Solution {
public:
    
    vector<int> p;
    int find(int x) {
        if(p[x] != x) p[x]=find(p[x]);
        return p[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i <= n; i++) p.push_back(i);
        for(auto& item : edges) {
            int a = item[0], b = item[1];
            if(find(a)==find(b)) return {a,b};
            p[find(a)] = find(b);
        }
        return {-1, -1};
    }
};
// 8ms 78.2%
// 9.8MB 100%
