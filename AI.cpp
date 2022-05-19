#include "Board.h"

const int attack[7] = { 0, 1, 64, 4096, 262144, 16777216, 1073741824 };
const int defend[7] = { 0, 1, 8, 512, 32768, 2097152, 134217728 };

long AttackPointInRow(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreRow = 0;
	int countO = 0, countX = 0, countO2 = 0, countX2 = 0;
	for (int iDem = 1; iDem < 6 && j + iDem < 12; iDem++) {
		if (board[i][j + iDem].getValue() == "O") countO++;
		else if (board[i][j + iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j + iDem2 < 12; iDem2++) {
				if (board[i][j + iDem2].getValue() == "O") countO2++;
				else if (board[i][j + iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j - iDem >= 0; iDem++) {
		if (board[i][j - iDem].getValue() == "O") countO++;
		else if (board[i][j - iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0; iDem2++) {
				if (board[i][j - iDem2].getValue() == "O") countO2++;
				else if (board[i][j - iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	scoreRow += (countX == 0) ? (attack[countO] * 2): attack[countO];
	scoreRow += (countO == 0) ? (defend[countX] * 2) : defend[countX];
	scoreRow += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countO == 4) scoreRow *= 2;
	return scoreRow;
}
long AttackPointInCol(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreCol = 0;
	int countO = 0, countX = 0, countO2 = 0, countX2 = 0;
	for (int iDem = 1; iDem < 6 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j].getValue() == "O") countO++;
		else if (board[i + iDem][j].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j].getValue() == "O") countO2++;
				else if (board[i + iDem2][j].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j].getValue() == "O") countO++;
		else if (board[i - iDem][j].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j].getValue() == "O") countO2++;
				else if (board[i - iDem2][j].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	scoreCol += (countX == 0) ? (attack[countO] * 2) : attack[countO];
	scoreCol += (countX2 == 0) ? (attack[countO2] * 2) : attack[countO2];
	scoreCol += (countO == 0) ? (defend[countX] * 2) : defend[countX];
	scoreCol += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countO == 4) scoreCol *= 2;
	return scoreCol;
}
long AttackPointInLeftDiagonal(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreLeftDiagonal = 0;
	int countO = 0, countX = 0, countO2 = 0, countX2 = 0;
	for (int iDem = 1; iDem < 6 && j + iDem < 12 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j + iDem].getValue() == "O") countO++;
		else if (board[i + iDem][j + iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j + iDem2 < 12 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j + iDem2].getValue() == "O") countO2++;
				else if (board[i + iDem2][j + iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j - iDem >= 0 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j - iDem].getValue() == "O") countO++;
		else if (board[i - iDem][j - iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j - iDem2].getValue() == "O") countO2++;
				else if (board[i - iDem2][j - iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	scoreLeftDiagonal += (countX == 0) ? (attack[countO] * 2): attack[countO];
	scoreLeftDiagonal += (countX2 == 0) ? (attack[countO2] * 2) : attack[countO2];
	scoreLeftDiagonal += (countO == 0) ? (defend[countX] * 2) : defend[countX];
	scoreLeftDiagonal += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countO == 4) scoreLeftDiagonal *= 2;
	return scoreLeftDiagonal;
}
long AttackPointInRightDiagonal(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreRightDiagonal = 0;
	int countO = 0, countX = 0, countO2 = 0, countX2 = 0;
	for (int iDem = 1; iDem < 6 && j - iDem >= 0 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j - iDem].getValue() == "O") countO++;
		else if (board[i + iDem][j - iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j - iDem2].getValue() == "O") countO2++;
				else if (board[i + iDem2][j - iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j + iDem < 12 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j + iDem].getValue() == "O") countO++;
		else if (board[i - iDem][j + iDem].getValue() == "X") {
			countX++;
			break;
		}
		else {
			for (int iDem2 = 2; iDem2 < 7 && j + iDem2 < 12 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j + iDem2].getValue() == "O") countO2++;
				else if (board[i - iDem2][j + iDem2].getValue() == "X") {
					countX2++;
					break;
				}
				else break;
			}
			break;
		}
	}
	scoreRightDiagonal += (countX == 0) ? (attack[countO] * 2) : attack[countO];
	scoreRightDiagonal += (countX2 == 0) ? (attack[countO2] * 2) : attack[countO2];
	scoreRightDiagonal += (countO == 0) ? (defend[countX] * 2): defend[countX];
	scoreRightDiagonal += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countO == 4) scoreRightDiagonal *= 2;
	return scoreRightDiagonal;
}
long DefendPointInRow(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreRow = 0;
	int countX = 0,countO = 0, countX2 = 0, countO2 = 0;
	for (int iDem = 1; iDem < 6 && j + iDem < 12; iDem++) {
		if (board[i][j + iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i][j + iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && j + iDem2 < 12; iDem2++) {
				if (board[i][j + iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i][j + iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j - iDem >= 0; iDem++) {
		if (board[i][j - iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i][j - iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0; iDem2++) {
				if (board[i][j - iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i][j - iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	scoreRow += (countO == 0) ? (defend[countX] * 2) : defend[countX];
	scoreRow += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countX == 4) scoreRow *= 2;
	return scoreRow;
}
long DefendPointInCol(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreCol = 0;
	int countX = 0, countO = 0, countX2 = 0, countO2 = 0;
	for (int iDem = 1; iDem < 6 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i + iDem][j].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i + iDem2][j].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i - iDem][j].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i - iDem2][j].getValue() == "X")
					countX2++;
				else break;
			}
			break;
		}
	}
	scoreCol += (countO == 0) ? (defend[countX] * 2) : defend[countX];
	scoreCol += (countO2 == 0) ? (defend[countX2] * 2) : defend[countX2];
	if (countX == 4) scoreCol *= 2;
	return scoreCol;
}
long DefendPointInLeftDiagonal(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreLeftDiagonal = 0;
	int countX = 0, countO = 0, countX2 = 0, countO2 = 0;
	for (int iDem = 1; iDem < 6 && j + iDem < 12 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j + iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i + iDem][j + iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && j + iDem2 < 12 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j + iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i + iDem2][j + iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j - iDem >= 0 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j - iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i - iDem][j - iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j - iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i - iDem2][j - iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	scoreLeftDiagonal += (countO == 2) ? (defend[countX] * 2) : defend[countX];
	scoreLeftDiagonal += (countO2 == 2) ? (defend[countX2] * 2) : defend[countX2];
	if (countX == 4) scoreLeftDiagonal *= 2;
	return scoreLeftDiagonal;
}
long DefendPointInRightDiagonal(Cell** board, int i, int j, const int attack[], const int defend[]) {
	long scoreRightDiagonal = 0;
	int countX = 0, countO = 0, countX2 = 0, countO2 = 0;
	for (int iDem = 1; iDem < 6 && j - iDem >= 0 && i + iDem < 12; iDem++) {
		if (board[i + iDem][j - iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i + iDem][j - iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem2 < 7 && j - iDem2 >= 0 && i + iDem2 < 12; iDem2++) {
				if (board[i + iDem2][j - iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i + iDem2][j - iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	for (int iDem = 1; iDem < 6 && j + iDem < 12 && i - iDem >= 0; iDem++) {
		if (board[i - iDem][j + iDem].getValue() == "O") {
			countO++;
			break;
		}
		else if (board[i - iDem][j + iDem].getValue() == "X") countX++;
		else {
			for (int iDem2 = 2; iDem < 7 && j + iDem2 < 12 && i - iDem2 >= 0; iDem2++) {
				if (board[i - iDem2][j + iDem2].getValue() == "O") {
					countO2++;
					break;
				}
				else if (board[i - iDem2][j + iDem2].getValue() == "X") countX2++;
				else break;
			}
			break;
		}
	}
	scoreRightDiagonal += (countO == 2) ? (defend[countX] * 2) : defend[countX];
	scoreRightDiagonal += (countO2 == 2) ? (defend[countX2] * 2) : defend[countX2];
	if (countX == 4) scoreRightDiagonal *= 2;
	return scoreRightDiagonal;
}