/**
 * Title:       main.cpp
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

#include "Sudoku.h"

/**
 * Main method that gets initialized upon start of the program and creates an instance of the class Sudoku. A function
 * belonging to the Sudoku class is called that will generate a completely solved sudoku board and then the pointer to
 * the class is deleted to free up the allocated memory.
 */
int main() {
    Sudoku * mySudoku = new Sudoku();
    mySudoku->solve();
    delete mySudoku;

    return 0;
}