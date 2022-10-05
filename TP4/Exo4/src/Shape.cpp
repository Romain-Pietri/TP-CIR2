#include "Shape.hpp"

#include <iostream>
using namespace std;

Shape::Shape() : id(rand() % 100) {
    color = rand() % 100;
}
int Shape::getID(){
    return id;
}
int Shape::getColor(){
    return color;
}
void Shape::setColor(int newColor){
    color = newColor;
}
