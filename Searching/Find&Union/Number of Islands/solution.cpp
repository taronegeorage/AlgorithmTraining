// leetcode 200.
// 16ms 63.99%
// 11.1MB 42.44%
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        count = 0;
        parent.resize(row*col);
        rank.resize(row*col);
        for(int i = 0; i < row; i++) 
            for(int j = 0; j < col; j++) {
                rank[i*col+j] = 0;
                parent[i*col+j] = -1;
                if(grid[i][j] == '1'){
                    parent[i*col+j] = i*col+j;
                    count++;
                }
            }
            
    };
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    };
    
    void union_ (int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if(rooti != rootj) {
            if(rank[rooti] > rank[rootj])
                parent[rootj] = rooti;
            else if(rank[rooti] < rank[rootj])
                parent[rooti] = rootj;
            else {
                parent[rootj] = rooti;
                rank[rooti] += 1;
            }
            count--;    
        }
    };
    int count;
    
private:
    // int parent[10000000];
    // int rank[10000000];
    vector<int> parent;// = {-1};
    vector<int> rank;// = {0};
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        UnionFind uf = UnionFind(grid);
        // for(int i = 0; i < 7; i++)
        //     cout << uf.parent[i] << " ";
        int direc[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '0')
                    continue;
                for(int l = 0; l < 4; l++) {
                    int nr = i + direc[l][0];
                    int nc = j + direc[l][1];
                    
                    if(nr>=0 && nc>=0 && nr<row && nc<col && grid[nr][nc]=='1') {
                        uf.union_(i*col+j, nr*col+nc);
                    }
                }
            }
        }
        return uf.count;
    }
};
