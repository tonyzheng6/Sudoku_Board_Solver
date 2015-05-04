/**
 * Title:       Sudoku.cpp
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

#include <iostream>
#include <time.h>
#include "Sudoku.h"
#include "Cell.h"

using namespace std;

/**
 * Constructor that gets instantiated when an instance of the Sudoku class is created and sets the
 * values of the sudoku board to 0.
 */
Sudoku::Sudoku() {
    SudokuBoard[9][9] = {0};
}

Sudoku::~Sudoku() {
    
}

/**
 * Function that prints out the values of the each cell in the sudoku board in a nice format.
 */
void Sudoku::printBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if ((j % 3 == 0) && (j != 0)) {
                cout << "| ";
            }
            
            cout << Board[i][j].getValue() << " ";
        }
        
        if ((i == 2) || (i == 5)) {
            cout << endl << "_ _ _   _ _ _   _ _ _" << endl;
        }
        
        cout << endl;
    }
    
    return;
}

/**
 * A helper function that checks if the rows of the sudoku board satisfy the constraints of the game.
 * Parameters taken are the row and column locations. A for loop iterates through the column and if the
 * value of the column matches with any of the other values in the column, then it violates the game
 * constraints and returns false, otherwise it returns true.
 */
bool Sudoku::checkRow(int row, int column) {
    for (int i = 0; i < 9; i++) {
        if (i != column) {
            if (Board[row][i].getValue() == Board[row][column].getValue()) {
                return false;
            }
        }
    }
    
    return true;
}

/**
 * A helper function that checks if the columns of the sudoku board satisfy the constraints of the game.
 * Parameters taken are the row and column locations. A for loop iterates through the row and if the value
 * of the row matches with any other values in the row, then it violates the game constraints and returns
 * false, otherwise it returns true.
 */
bool Sudoku::checkColumn(int row, int column) {
    for (int i = 0; i < 9; i++) {
        if (i != row) {
            if (Board[i][column].getValue() == Board[row][column].getValue()) {
                return false;
            }
        }
    }
    
    return true;
}

/**
 * A helper function that checks if the columns of the sudoku board satisfy the constraints of the game.
 * Parameters taken are the row and column locations. The row and column locations are divided by 3 and the
 * square grid location is found since integer values truncate the results. A nested for loop iterates 
 * through the square grid and if the value matches with any other values in the row or column of the 
 * square grid, then it violates the game constraints and returns false, otherwise it returns true.
 */
bool Sudoku::checkSquare(int row, int column) {
    int SquareRow = row / 3;
    int SquareColumn = column / 3;
    
    for (int i = SquareRow * 3; i < (SquareRow * 3 + 3); i++) {
        for (int j = SquareColumn * 3; j < (SquareColumn * 3 + 3); j++) {
            if (i != row || j != column) {
                if (Board[row][column].getValue() == Board[i][j].getValue()) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

/**
 * A function that checks if the value in the cell of the sudoku board fits the constraints
 * of the game and if it passes the constraint checks, it has completed a solved sudoku board.
 * Parameters taken are the starting row and column locations and if the board's cell is valid
 * it continues through the board, otherwise it will continue generating a random number for 
 * that cell and check the validity constraints on it until it returns true.
 */
bool Sudoku::checkConstraints(int row, int column) {
    while (Board[row][column].getValid() == true) {
        column++;
        
        if (column > 8) {
            column = 0;
            row++;
        }
        
        if (row > 8) {
            return true;
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        int TempRow, TempColumn;
        
        Board[row][column].setValue(rand() % 9 + 1);
        
        if (checkColumn(row, column) && checkRow(row, column) && checkSquare(row, column)) {
            TempColumn = column + 1;
            TempRow = row;
            
            if (TempColumn > 8) {
                TempColumn = 0;
                TempRow++;
            }
            
            if (TempRow > 8) {
                return true;
            }
            
            if (checkConstraints(TempRow, TempColumn)) {
                return true;
            }
        }
        else {
            
        }
    }
    
    Board[row][column].setValue(0);

    return false;
}

/**
 * A function that checks if the values in the cells of the board are valid or not
 * by checking if it is 0, otherwise it will set the cell's validity to true and 
 * copy over the value of the cell.
 */
void Sudoku::fillBoard() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (SudokuBoard[i][j] == 0) {
                Board[i][j].setValid(false);
                Board[i][j].setValue(0);
            }
            else {
                Board[i][j].setValid(true);
                Board[i][j].setValue(SudokuBoard[i][j]);
            }
        }
    }
    
    return;
}

/**
 * A function that is called upon to call other functions of the class that will
 * seed the random number generator, fill the first cell of the board, and recursively
 * solve a sudoku board.
 */
void Sudoku::solve() {
    srand(time(NULL));
    int x = rand() % 9 + 1;
    cout << "The top left cell will have a(n) " << x << "\n" << endl;
    
    SudokuBoard[0][0] = (x);
    fillBoard();
    checkConstraints(0,0);

    cout << "Solved Sudoku Puzzle: \n" << endl;
    
    printBoard();
    
    return;
}