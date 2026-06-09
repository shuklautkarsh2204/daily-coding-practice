# include <iostream>
# include <vector>
using namespace std;

class Solution {
    public:
    // first check whether its valid..
        bool isValid(vector<vector<char>>& board, int row, int col, char num){
            // col check
            for (int i = 0; i<9; i++){
                if (board[i][col] == num){
                    return false;
                }
            }
            // row check
            for (int j = 0; j<9; j++){
                if (board[row][j] == num){
                    return false;
                }
            }
            // 3x3 box check
            int boxRow = (row / 3) * 3;
            int boxCol = (col / 3) * 3;
            for (int i = boxRow; i < boxRow + 3; i++){
                for (int j = boxCol; j < boxCol + 3; j++){
                    if (board[i][j] == num){
                        return false;
                    }
                }
            }
            return true;
        }
        bool solve(vector<vector<char>>& board){
            for (int i = 0; i<9; i++){
                for (int j = 0; j<9; j++){
                    if (board[i][j] == '.'){
                        for (char num = '1'; num <= '9'; num++){
                            if (isValid(board, i, j, num)){
                                board[i][j] = num;
                                if (solve(board)){
                                    return true;
                                }
                                else{
                                    board[i][j] = '.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
};