#include "Game.h"

int countChessX = 0, countChessO = 0;
Game::Game() {}
void Game::loadGame() {
    int row = 12, col = 12, colWidth = 3, rowWidth = 1;
    caroBoard.setBoard(row, col, rowWidth, colWidth);
}
void Game::PlayWithComputer() {
    loadGame();
    int row_index = 0, col_index = 0; 
	bool isX = true, isUser = true;
	caroBoard.drawBoard();
	gotoXY(32, 3);
	cout << "New Game";
	gotoXY(72, 3);
	cout << "Quit Game";
	gotoXY(52, 3);
	cout << "Turn of " << ((isX) ? "X" : "O");
	gotoXY(caroBoard.getXInit(), caroBoard.getYInit());
	bool isNewGame = false, isQuitGame = false;
	while (true) {
		bool isPressed = false;
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
			if (row_index > 0) row_index -= 1;
			else if (row_index == 0) {
				gotoXY(32, 3);
				textColor(2);
				cout << "New Game";
				textColor(7);
				isNewGame = true;
				isQuitGame = false;
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
			if (row_index < caroBoard.getRow() - 1) row_index += 1;
			if (isNewGame) {
				isNewGame = false;
				gotoXY(32, 3);
				textColor(7);
				cout << "New Game";
			}
			if (isQuitGame) {
				isNewGame = false;
				gotoXY(72, 3);
				textColor(7);
				cout << "Quit Game";
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
			if (col_index > 0) col_index -= 1;
			else if (col_index == 0) {
				if (row_index > 0) row_index -= 1;
				else if (row_index == 0) row_index = caroBoard.getRow() - 1;
				col_index = caroBoard.getCol() - 1;
			}
			if (isQuitGame) {
				gotoXY(72, 3);
				textColor(7);
				cout << "Quit Game";
				gotoXY(32, 3);
				textColor(2);
				cout << "New Game";
				textColor(7);
				isNewGame = true;
				isQuitGame = false;
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
			if (col_index < caroBoard.getCol() - 1) col_index += 1;
			else if (col_index == caroBoard.getCol() - 1) {
				if (row_index < caroBoard.getRow() - 1) row_index += 1;
				else if (row_index == caroBoard.getRow() - 1) row_index = 0;
				col_index = 0;
			}
			if (isNewGame) {
				gotoXY(32, 3);
				textColor(7);
				cout << "New Game";
				gotoXY(72, 3);
				textColor(2);
				cout << "Quit Game";
				textColor(7);
				isQuitGame = true;
				isNewGame = false;
			}
			isPressed = true;
		}
		if (isNewGame) {
			if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
				system("cls");
				Sleep(100);
				PlayWithComputer();
			}
		}
		if (isQuitGame) {
			if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
				system("cls");
				Sleep(100);
				startGame();
			}
		}
		if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) && isUser &&
        caroBoard.getCellValue(row_index, col_index) == " ") {
			Sleep(100);
            caroBoard.setCellValue(row_index, col_index, "X");
			if (isX) textColor(12);
			else textColor(1);
			cout << caroBoard.getCellValue(row_index, col_index);
			textColor(7);
			isX = false;
			countChessX++;
			isPressed = true;
			isUser = false;
		}
		else if (!isUser) {
			Sleep(100);
			Cell computer;
			if (countChessO == 0) computer = { (row_index + 1) % caroBoard.getRow(), col_index + 1 % caroBoard.getCol(), "O" };
			else computer =  caroBoard.getAISolution();
            caroBoard.setCellValue(computer.getX(), computer.getY(), "O");
			textColor(1);
			gotoXY(caroBoard.getXInit() + computer.getY() * (caroBoard.getColWidth() + 1), caroBoard.getYInit() + computer.getX() * (caroBoard.getRowWidth() + 1));
            cout << caroBoard.getCellValue(computer.getX(), computer.getY());
			isX = true;
			isPressed = true;
			isUser = true;
			countChessO++;
		}
		if (isPressed && !isNewGame && !isQuitGame) {
			gotoXY(52, 3);
			textColor(6);
			cout << "Turn of " << ((isX) ? "X" : "O");
			gotoXY(caroBoard.getXInit() + col_index * (caroBoard.getColWidth() + 1), caroBoard.getYInit() + row_index * (caroBoard.getRowWidth() + 1));
		}
		Sleep(100);
		if (GetAsyncKeyState(VK_ESCAPE) || caroBoard.isFullBoard()) {
			gotoXY(52, 3);
			cout << "Game Over\n";
			break;
		}
		if (caroBoard.getWinner() != " ") {
			gotoXY(52, 3);
			cout << "Winner is " << caroBoard.getWinner() << endl;
			break;
		}
	}
	gotoXY(20,30);
	textColor(12);
	cout << "Ban co muon choi lai khong ? Nhan Space hoac Enter de choi lai\n";
	if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
		system("cls");
		PlayWithComputer();
	}
    if(GetAsyncKeyState(VK_ESCAPE)) {
        system("cls");
        Sleep(100);
        startGame();
    }
	system("pause");
}
void Game::PlayWithPlayer() {
    loadGame();
    int row_index = 0, col_index = 0; 
	bool isX = true, isUser = true;
	caroBoard.drawBoard();
	gotoXY(32, 3);
	cout << "New Game";
	gotoXY(72, 3);
	cout << "Quit Game";
	gotoXY(52, 3);
	cout << "Turn of " << ((isX) ? "X" : "O");
	gotoXY(caroBoard.getXInit(), caroBoard.getYInit());
	bool isNewGame = false, isQuitGame = false;
	while (true) {
		bool isPressed = false;
		if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) {
			if (row_index > 0) row_index -= 1;
			else if (row_index == 0) {
				gotoXY(32, 3);
				textColor(2);
				cout << "New Game";
				textColor(7);
				isNewGame = true;
				isQuitGame = false;
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) {
			if (row_index < caroBoard.getRow() - 1) row_index += 1;
			if (isNewGame) {
				isNewGame = false;
				gotoXY(32, 3);
				textColor(7);
				cout << "New Game";
			}
			if (isQuitGame) {
				isNewGame = false;
				gotoXY(72, 3);
				textColor(7);
				cout << "Quit Game";
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) {
			if (col_index > 0) col_index -= 1;
			else if (col_index == 0) {
				if (row_index > 0) row_index -= 1;
				else if (row_index == 0) row_index = caroBoard.getRow() - 1;
				col_index = caroBoard.getCol() - 1;
			}
			if (isQuitGame) {
				gotoXY(72, 3);
				textColor(7);
				cout << "Quit Game";
				gotoXY(32, 3);
				textColor(2);
				cout << "New Game";
				textColor(7);
				isNewGame = true;
				isQuitGame = false;
			}
			isPressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')) {
			if (col_index < caroBoard.getCol() - 1) col_index += 1;
			else if (col_index == caroBoard.getCol() - 1) {
				if (row_index < caroBoard.getRow() - 1) row_index += 1;
				else if (row_index == caroBoard.getRow() - 1) row_index = 0;
				col_index = 0;
			}
			if (isNewGame) {
				gotoXY(32, 3);
				textColor(7);
				cout << "New Game";
				gotoXY(72, 3);
				textColor(2);
				cout << "Quit Game";
				textColor(7);
				isQuitGame = true;
				isNewGame = false;
			}
			isPressed = true;
		}
		if (isNewGame) {
			if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
				system("cls");
				Sleep(100);
				PlayWithPlayer();
			}
		}
		if (isQuitGame) {
			if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
				system("cls");
				Sleep(100);
				startGame();
			}
		}
		if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) && isUser && caroBoard.getCellValue(row_index, col_index) == " ") {
			Sleep(100);
			string value = (isX) ? "X" : "O";
            caroBoard.setCellValue(row_index, col_index, value);
			if (isX) textColor(12);
			else textColor(1);
			cout << caroBoard.getCellValue(row_index, col_index);
			textColor(7);
			isX = !isX;
			isPressed = true;
		}
		if (isPressed && !isNewGame && !isQuitGame) {
			gotoXY(52, 3);
			textColor(6);
			cout << "Turn of " << ((isX) ? "X" : "O");
			gotoXY(caroBoard.getXInit() + col_index * (caroBoard.getColWidth() + 1), caroBoard.getYInit() + row_index * (caroBoard.getRowWidth() + 1));
		}
		Sleep(100);
		if (GetAsyncKeyState(VK_ESCAPE) || caroBoard.isFullBoard()) {
			gotoXY(52, 3);
			cout << "Game Over\n";
			break;
		}
		if (caroBoard.getWinner() != " ") {
			gotoXY(52, 3);
			cout << "Winner is " << caroBoard.getWinner() << endl;
			break;
		}
	}
	gotoXY(20, 30);
	textColor(12);
	cout << "Ban co muon choi lai khong ? Nhan Space hoac Enter de choi lai\n";
	if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_SPACE)) {
		system("cls");
		PlayWithPlayer();
	}
    if(GetAsyncKeyState(VK_ESCAPE)) {
        system("cls");
        Sleep(100);
        startGame();
    }
	system("pause");
}
void Game::getStudentInfo() {
	string file = "student.txt";
	ifstream ifs(file);
	string line;
	int index = 5;
	while (!ifs.eof()) {
		gotoXY(40, index);
		if (index == 5) textColor(3);
		else textColor(7);
		getline(ifs, line);
		cout << line << endl;
		Sleep(100);
		index += 2;
	}
	textColor(12);
	gotoXY(40, index);
	cout << "Nhap phim Enter hoac Space de bat dau choi game " << endl;
	textColor(7);
	system("pause");
	if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
		system("cls");
		startGame();
	}
}
void Game::getRule() {
	string file = "rules.txt";
	ifstream ifs(file);
	string line;
	while (!ifs.eof()) {
		getline(ifs, line);
		if (line == "Luat choi") {
			cout << "\n\t";
			textColor(3);
		}
		else if (line[0] > '0' && line[0] < '9') {
			cout << "\t";
			textColor(2);
		}
		else textColor(7);
		cout << line << endl;
		Sleep(100);
	}
	textColor(12);
	cout << "\n\tNhap phim Enter hoac Space de bat dau choi game " << endl;
	textColor(7);
	system("pause");
	if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
		system("cls");
		startGame();
	}
}
void Game::startGame() {
    resizeWindow(1000, 600);
    string file = "title.txt";
	cout << "\n\n\n";
	ifstream ifs(file);
	string line;
	textColor(2);
	while (!ifs.eof()) {
		getline(ifs, line);
		cout << line << endl;
		Sleep(100);
	}
	textColor(7);
	int count = 0, index = 0;
	bool isPress = false;
	int color[] = { 12,7,7,7,7 };
	string option[] = { "1. Choi voi may","2. Choi 2 nguoi","3. Luat choi","4. Thong tin sinh vien", "5. Thoat ra" };
	gotoXY(45, 15);
	textColor(3);
	cout << "Choose your option" << endl;
	textColor(3);
	while (true) {
		gotoXY(45, 17 + 2 * index);
		textColor(color[index]);
		cout << option[index] << endl;
		if (GetAsyncKeyState(VK_UP)) {
			Sleep(100);
			count--;
			if (count < 0) count = 4;
			isPress = true;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			Sleep(100);
			count++;
			if (count > 4) count = 0;
			isPress = true;
		}
		if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_RETURN)) {
			if (count == 0) {
				system("cls");
				textColor(7);
				PlayWithComputer();
			}
			else if (count == 1) {
				system("cls");
				textColor(7);
				PlayWithPlayer();
			}
			else if (count == 2) {
				system("cls");
				getRule();
			}
			else if (count == 3) {
				system("cls");
				getStudentInfo();
			}
			else if (count == 4) break;
		}
		if (isPress) {
			for (int i = 0; i < 5; i++) color[i] = 7;
			color[count] = 12;
			gotoXY(45, 15 + 2 * count);
		}
		Sleep(100);
		index++;
		if (index == 5) index = 0;
	}
	gotoXY(45, 25);
}
Game::~Game() {}