//36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<int,unordered_map<char,int>> row;
        unordered_map<int,unordered_map<char,int>> col;
        unordered_map<int,unordered_map<char,int>> grid;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int cell = board[i][j];
                
                if(cell!='.'){
                    //validate rows
                    if(row[i][cell]++>0){ return false;}
                    //validate cols
                    if(col[j][cell]++>0){ return false;}
                     //validate squares
                    int grid_cell = (i/3)*3 +j/3;
                    if(grid[grid_cell][cell]++>0){ return false;}
                }

            }
        }
        return true;
        
    }
};