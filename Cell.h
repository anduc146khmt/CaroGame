#ifndef CELL_H
#define CELL_H
#include "Graphic.cpp"
#include <iostream>
#include <string.h>
using namespace std;
class Cell {
private:
    int x; // Tọa độ x, y
    int y;
    string value;  // Giá trị "X", "O", hoặc " " của ô
public:
    // Constructor
    Cell();
    Cell(int x, int y, string value);
    // Set method
    void setX(int x);
    void setY(int y);
    void setValue(string value);    
    // Get method
    int getX();
    int getY();
    string getValue();
    // Destructor
    ~Cell();
};
#endif