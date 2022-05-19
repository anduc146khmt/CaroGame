#ifndef BOARD_H
#define BOARD_H
#include "Cell.cpp"
#include <iostream>
using namespace std;
class Board {
private:
    int row;
    int col;
    int rowWidth;
    int colWidth;
    int x_init = 34, y_init = 5;
    Cell** board;  // Board
public:
    Board();
    Board(int row, int col, int rowWidth, int colWidth);
    // Get method
    int getRow();
    int getCol();
    int getRowWidth();
    int getColWidth();
    int getXInit();
    int getYInit();
    Cell** getBoard();
    // Change cell value
    void setCellValue(int i, int j, string value);
    void setBoard(int row, int col, int rowWidth, int colWidth);
    string getCellValue(int i, int j);
    // Draw board
    void drawTopBoard();
    void blockBoard(int index);
    void drawBottomBoard();
    void drawBoard();
    // Rule of the game
    bool isSafe(int i, int j);
    bool checkRow(int i, int j);
    bool checkCol(int i, int j);
    bool checkLeftDiagonal(int i, int j);
    bool checkRightDiagonal(int i, int j);
    string getWinner();
    // Check fullboard
    bool isFullBoard();
    // Intialize board
    void resetBoard();
    // Print board
    void printBoard();
    // Build AI Player (Play with computer). Source code implement AI Bot in AI.cpp
    Cell findBlankCell();
    Cell getAISolution();
    ~Board();
};
#endif