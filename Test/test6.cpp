#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        count = 0;
        parent.resize(row*col);
        rank.resize(row*col);
        for(int i = 0; i < row; i++) 
            for(int j = 0; j < col; j++) {
                rank[i*col+row] = 0;
                parent[i*col+row] = -1;
                if(grid[i][j] == '1'){
                    parent[i*col+row] = i*col+row;
                    count++;
                }
            }
    };
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(i);
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
    vector<int> parent;
    vector<int> rank;
};



class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        UnionFind uf = UnionFind(grid);
        int direc[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '0')
                    continue;
                for(auto& d : direc) {
                    int nr = i + d[0];
                    int nc = j + d[1];
                    if(nr>=0 && nc>=0 && nr<row && nc<col && grid[nr][nc]=='1')
                        uf.union_(i*col+j, nr*col+nc);
                }
            }
        }
        return uf.count;
    }
};
