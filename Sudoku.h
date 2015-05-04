/**
 * Title:       Sudoku.h
 * Author:      Tony Zheng
 * Created on:  2/23/2014
 * Modified on: 5/1/2015
 * Description: A program that will generate solved Sudoku boards. The program starts by
 *              inserting a random number (between 1 and 9) in the top left cell of the grid
 *              and then places other numbers in the remaining cells to satisfy the constraints
 *              of the puzzle. The solution is done recursively and uses a backtracking algorithm
 * Build with:  To compile: g++ *.cpp -o run.me
 *              To run:     ./run.me
 */

#ifndef Sudoku_Solver_Sudoku_h
#define Sudoku_Solver_Sudoku_h

#include "Cell.h"

class Sudoku {
private:
    Cell Board[9][9];
    
public:
    Sudoku();
    ~Sudoku();
    int SudokuBoard[9][9];
    bool checkRow(int row, int column);
    bool checkColumn(int row, int column);
    bool checkSquare(int row, int column);
    bool checkConstraints(int row, int column);
    void fillBoard();
    void printBoard();
    void solve();
};

#endif
