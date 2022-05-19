#include "Board.h"
#include "AI.cpp"
using namespace std;
Board::Board() {
    this->row = 0;
    this->col = 0;
    this->rowWidth = 0;
    this->colWidth = 0;
    this->board = nullptr;
}
Board::Board(int row, int col, int rowWidth, int colWidth) {
    this->row = row;
    this->col = col;
    this->rowWidth = rowWidth;
    this->colWidth = colWidth;
    this->board = new Cell* [this->row];
    for(int i = 0; i < row; i++) {
        board[i] = new Cell[col];
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j].setX(x_init + j * (colWidth + 1));
            board[i][j].setX(y_init + i * (rowWidth + 1));
            board[i][j].setValue(" ");
        }
    }
}
int Board::getRow() { 
    return this->row; 
}
int Board::getCol() { 
    return this->col; 
}
int Board::getRowWidth() { 
    return this->rowWidth; 
}
int Board::getColWidth() { 
    return this->colWidth; 
}
int Board::getXInit() { 
	return this->x_init;
}
int Board::getYInit() { 
	return this->y_init;
}
Cell** Board::getBoard() {
	return this->board;
}
void Board::setCellValue(int i, int j, string value) {
	this->board[i][j].setValue(value);
}
void Board::setBoard(int row, int col, int rowWidth, int colWidth) {
	this->row = row;
    this->col = col;
    this->rowWidth = rowWidth;
    this->colWidth = colWidth;
    this->board = new Cell* [this->row];
    for(int i = 0; i < row; i++) {
        board[i] = new Cell[col];
    }
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j].setX(x_init + j * (colWidth + 1));
            board[i][j].setX(y_init + i * (rowWidth + 1));
            board[i][j].setValue(" ");
        }
    }
}
string Board::getCellValue(int i, int j) {
    return this->board[i][j].getValue();
}
void Board::drawTopBoard() {
    cout << "\n\t\t\t\t\t\t" << "Welcome to Game Caro\n";
	cout << "\n\n\t\t\t\t" << char(218); // ┌
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < colWidth; j++) {
			cout << char(196); // ─
		}
		if (i == col - 1) cout << char(191) << endl; // ┐
		else cout << char(194); //  ┬
	}
}
void Board::blockBoard(int index) {
    for (int r = 0; r < rowWidth; r++) {
		cout << "\t\t\t\t" << char(179); // │
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < colWidth; j++) {
				if (r == 0 && j == 1) cout << board[index][i].getValue();
				else cout << " ";
			}
			cout << char(179); // │
		}
		cout << endl;
	}
	if (index < col - 1) {
		cout << "\t\t\t\t" << char(195); // ├
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < colWidth; j++) {
				cout << char(196); // ─
			}
			if (i == col - 1) cout << char(180) << endl; //  ┤
			else cout << char(197); //  ┼
		}
	}
}
void Board::drawBottomBoard() {
    cout << "\t\t\t\t" << char(192); // └
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < colWidth; j++) {
			cout << char(196); // ─
		}
		if (i == col - 1) cout << char(217) << endl; // ┘
		else cout << char(193); //  ┬
	}
}
void Board::drawBoard() {
    drawTopBoard();
	for (int i = 0; i < row; i++) {
		blockBoard(i);
	}
	drawBottomBoard();
}
bool Board::isSafe(int i, int j) {
	return i >= 0 && i < row && j >= 0 && j < col;
}
bool Board::checkRow(int i, int j) {
	if (board[i][j].getValue() == " ") return false;
	for (int k = j - 2; k <= j + 2; k++) {
		if (!isSafe(i, k)) return false;
		if (board[i][k].getValue() != board[i][j].getValue()) return false;
	}
	return true;
}
bool Board::checkCol(int i, int j) {
	if (board[i][j].getValue() == " ") return false;
	for (int k = i - 2; k <= i + 2; k++) {
		if (!isSafe(k, j)) return false;
		if (board[k][j].getValue() != board[i][j].getValue()) return false;
	}
	return true;
}
bool Board::checkLeftDiagonal(int i, int j) {
	if (board[i][j].getValue() == " ") return false;
	for (int k = -2; k <= 2; k++) {
		if (!isSafe(i + k, j + k)) return false;
		if (board[i + k][j + k].getValue() != board[i][j].getValue()) return false;
	}
	return true;
}
bool Board::checkRightDiagonal(int i, int j) {
	if (board[i][j].getValue() == " ") return false;
	for (int k = -2; k <= 2; k++) {
		if (!isSafe(i + k, j - k)) return false;
		if (board[i + k][j - k].getValue() != board[i][j].getValue()) return false;
	}
	return true;
}
string Board::getWinner() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (checkRow(i, j) || checkCol(i, j)
			|| checkLeftDiagonal(i, j) || checkRightDiagonal(i, j)) {
				return board[i][j].getValue();
			}
		}
	}
	return " ";
}
bool Board::isFullBoard() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j].getValue() == " ") return false;
		}
	}
	return true;
}
void Board::resetBoard() {
	 for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j].setX(x_init + j * (colWidth + 1));
            board[i][j].setX(y_init + i * (rowWidth + 1));
            board[i][j].setValue(" ");
        }
    }
}
void Board::printBoard() {
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << board[i][j].getValue() << " ";
		}
		cout << endl;
	}
}
Cell Board::findBlankCell() {
	for (int i = -1; i < 1; i++) {
		for (int j = -1; j < 1; j++) {
			if (!isSafe(row + i, col + j)) continue;
			if (board[row + i][col + j].getValue() == " ") return { row + i, col + j, "O" };
		}
	}
	return { 0,0, "O" };
}
Cell Board::getAISolution() {
	Cell res;
	long resPoint = 0;
	int resRow = 0, resCol = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			long AttackPoint = 0;
			long DefendPoint = 0;
			if (board[i][j].getValue() == " ") {
				AttackPoint += AttackPointInCol(board, i, j, attack, defend);
				AttackPoint += AttackPointInRow(board, i, j, attack, defend);
				AttackPoint += AttackPointInLeftDiagonal(board, i, j, attack, defend);
				AttackPoint += AttackPointInRightDiagonal(board, i, j, attack, defend);
				DefendPoint += DefendPointInCol(board, i, j, attack, defend);
				DefendPoint += DefendPointInRow(board, i, j, attack, defend);
				DefendPoint += DefendPointInLeftDiagonal(board, i, j, attack, defend);
				DefendPoint += DefendPointInRightDiagonal(board, i, j, attack, defend);
				long maxPoint = (AttackPoint > DefendPoint) ? AttackPoint : DefendPoint;
				if (resPoint < maxPoint) {
					resPoint = maxPoint;
					resRow = i;
					resCol = j;
				}
			}
		}
	}
	res.setX(resRow);
	res.setY(resCol);
	res.setValue("O");
	return res;
}
Board::~Board() {}