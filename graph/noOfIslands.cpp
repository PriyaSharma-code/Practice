//200. Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n = m? grid[0].size() : 0;
        int islands = 0;
        for(int i = 0; i<m ; i++){
            for(int j= 0; j< n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    eraseIslands(grid,i,j);
                }
            }
        }
        return islands;
    }
    
    void eraseIslands(vector<vector<char>> &grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i == m || j<0 || j==n || grid[i][j]=='0'){
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i-1,j);
        eraseIslands(grid,i, j-1);
        eraseIslands(grid, i+1 , j);
        eraseIslands(grid, i , j+1);
    }
};