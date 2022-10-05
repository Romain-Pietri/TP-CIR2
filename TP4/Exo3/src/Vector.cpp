#include "Vector.hpp"
#include <iostream>
using namespace std;

Vector::Vector(){
    start.setX(0);
    start.setY(0);
}
Vector::Vector(Point2D start, Point2D end){
    this->start = start;
    this->end = end;
}
Vector::Vector(int x1, int y1, int x2, int y2){
    start.setX(x1);
    start.setY(y1);
    end.setX(x2);
    end.setY(y2);
}
Vector::Vector(const Vector& v){
    start = v.start;
    end = v.end;
}
void Vector::Addition(const Vector& v){
    start.setX(start.getX() + v.start.getX());
    start.setY(start.getY() + v.start.getY());
    end.setX(end.getX() + v.end.getX());
    end.setY(end.getY() + v.end.getY());
}
void Vector::Multiplication(float scalar){
    start.setX(start.getX() * scalar);
    start.setY(start.getY() * scalar);
    end.setX(end.getX() * scalar);
    end.setY(end.getY() * scalar);
}
bool Vector::isEqual(const Vector& v){
    if(end.getX()-start.getX() == v.end.getX()-v.start.getX() && end.getY()-start.getY() == v.end.getY()-v.start.getY()){
        return true;
    }
    return false;
}


