/**
 * Title:       Cell.cpp
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

#include "Cell.h"

Cell::Cell() {
    
}

Cell::~Cell() {
    
}

/**
 * Setters and getters for the Cell class.
 */
void Cell::setValue(int value) {
    this->value = value;
};

int Cell::getValue() {
    return value;
};

void Cell::setValid(bool valid) {
    this->valid = valid;
};

bool Cell::getValid() {
    return valid;
};