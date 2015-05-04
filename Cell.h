/**
 * Title:       Cell.h
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

#ifndef Sudoku_Solver_Cell_h
#define Sudoku_Solver_Cell_h

class Cell {

private:
    int value = 0;
    bool valid = false;

public:
    Cell();
    ~Cell();
    void setValue(int value);
    int getValue();
    void setValid(bool valid);
    bool getValid();
};

#endif
