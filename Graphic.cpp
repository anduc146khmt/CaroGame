#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <Windows.h>

// Hàm thay đổi kích thước window của khung console.
void resizeWindow(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Hàm tô màu.
void textColor(int color) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdout, color);
}
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoXY(int x, int y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hStdout, position);
}
// Hàm xóa màn hình.
void clearScreen() {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = 0;
    position.Y = 0;
    SetConsoleCursorPosition(hStdout, position);
}
#endif