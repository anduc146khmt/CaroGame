#include "Cell.h"

Cell::Cell() {
    this->x = 0;
    this->y = 0;
    this->value = " ";
}
Cell::Cell(int x, int y, string value) {
    this->x = x;
    this->y = y;
    this->value = value;
}
void Cell::setX(int x) { 
    this->x = x; 
}
void Cell::setY(int y) { 
    this->y = y; 
}
void Cell::setValue(string value) { 
    this->value = value; 
}
int Cell::getX() { 
    return this->x; 
}
int Cell::getY() { 
    return this->y;
}
string Cell::getValue() {
    return this->value;
}
Cell::~Cell() {}