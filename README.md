# Sudoku_Board_Solver
Sudoku is a logic-based, combinatorial number-placement puzzle.
- ===============
- | 4 9 1 | 2 3 7 | 5 6 8 |
- | 5 7 8 | 1 9 6 | 2 3 4 |
- | 6 3 2 | 4 5 8 | 7 9 1 |
- ===============
- | 8 1 6 | 7 4 3 | 9 5 2 |
- | 2 4 7 | 5 8 9 | 6 1 3 |
- | 9 5 3 | 6 1 2 | 4 8 7 |
- ===============
- | 1 2 9 | 3 6 4 | 8 7 5 |
- | 3 8 4 | 9 7 5 | 1 2 6 |
- | 7 6 5 | 8 2 1 | 3 4 9 |
- ===============

The objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 sub-grids that compose the grid contains all the digits from 1 to 9. Duplicate numbers may not appear twice in the same row, column or in any of the nine 3x3 sub-grids of the 9x9 playing board. Above is one example of a valid Sudoku board. 

The objective for this program is to generate valid Sudoku boards. The program should begin by placing a random number between 1 and 9 in the top left cell of the grid. It should then place other numbers in the remaining cells to satisfy the constraints of the puzzle.
