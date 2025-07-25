//37. Sudoku Solver

/*
    Problem Statment:
       Write a program to solve a Sudoku puzzle by filling the empty cells.

        A sudoku solution must satisfy all of the following rules:

        Each of the digits 1-9 must occur exactly once in each row.
        Each of the digits 1-9 must occur exactly once in each column.
        Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
        The '.' character indicates empty cells.
*/

/*
    Approach:
         we will need 3 functions:
        - isValid: This function will be used to check if it is valid to place a number at a given position.
        - solveSudoku: This function will be used to solve the Sudoku puzzle using backtracking.
        - solveSudokuUtil: This function will be used to fill the empty cells recursively.

    solveSudoku :
    // parameters:
        - board: the input Sudoku board.
    Logic:
        1. call the recursive function to fill the empty cells.
        // solveSudokuUtil(board):
        2. return the solved board. 

    solveSudokuUtil : 
    // parameters:
        - board: the input Sudoku board.
    Logic:
        // base case:
        1. iterate through the rows and columns of the board:
            - if the cell is empty ('.'), try placing numbers from 1 to 9.
            // for(int i=0;i<9;i++) {
            //     for(int j=0;j<9;j++) {
            //         if(board[i][j] == '.') {
            //             for(char num='1';num<='9';num++) {
        2. for each number, check if it is valid to place it at the current position using the isValid function.
            //                 if(isValid(board, i, j, num)) {
        3. if it is valid, place the number and recursively call the function to fill the next cell.
            //                     board[i][j] = num;
        4. if the recursive call returns true, it means the board is solved.
            //                     if(solveSudokuUtil(board)) return true;
        5. if the recursive call returns false, backtrack by removing the number from the current cell.
            //                     board[i][j] = '.';
        6. if no number can be placed, return false to backtrack.
            //                 }
            //             }
            //         }
            //     }
        7. if all cells are filled, return true to indicate the board is solved.
            // return true;
        8. return false if no solution is found.

    
    isValid :
    // parameters:
        - board: the input Sudoku board.
        - row: the current row index.
        - col: the current column index.
        - num: the number to be placed.
    Logic:
        1. check if the number already exists in the current row.
            // for(int i=0;i<9;i++) {
            //     if(board[row][i] == num) return false;
        2. check if the number already exists in the current column.
            // }
            // for(int i=0;i<9;i++) {
            //     if(board[i][col] == num) return false;
        3. check if the number already exists in the current 3x3 sub-box.
            // }
            // int startRow = (row / 3) * 3;
            // int startCol = (col / 3) * 3;
            // for(int i=0;i<3;i++) {
            //     for(int j=0;j<3;j++) {
            //         if(board[startRow + i][startCol + j] == num) return false;
        4. return true if the number can be placed at the current position.
            //         }
            //     }
            // }


*/

/*
    time complexity: O(9^(n*n)), where n is the size of the Sudoku board (9 in this case). In the worst case, we may have to try all numbers for each empty cell.
    space complexity: O(n*n), where n is the size of the Sudoku board. The

*/

#include <iostream>
#include <vector>
using namespace std;


bool isValid(vector<vector<char>> &board, int row, int col, int num){
    // check if the number already exists in the current row
    for(int i=0;i<9;i++){
        if(board[row][i]== '0'+num) return false;

    }
    // check if the number already exists in the current column
    for(int i=0;i<9;i++){
        if(board[i][col]== '0'+num) return false;
    }

    // check if the number already exists in the current 3x3 sub-box
    int startrow=(row/3)*3;
    int startcol=(col/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[startrow+i][startcol+j]== '0'+num) return false;
        }
    }
    return true;
}

bool solveSudokuUtil(vector<vector<char>>& board){

    //basecase: if all cells are filled, return true

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(int num=1;num<=9;num++){
                    if(isValid(board,i,j,num)){
                        board[i][j]= '0'+num; // Place the number
                        if(solveSudokuUtil(board)) return true; // Recur to fill the next cell
                        board[i][j]= '.'; // Backtrack
                    }
                }
                return false; // No number can be placed, backtrack
            }
        }
    }
    return true; // All cells are filled
}



vector<vector<char>> solveSudoku(vector<vector<char>> &board){
    solveSudokuUtil(board);
    return board;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char>> solvedBoard = solveSudoku(board);

    // Output the solved Sudoku board
    for (const auto &row : solvedBoard) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
