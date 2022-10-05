#include "Point2D.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Point2D::Point2D() {
    x = rand() % 100;
    y = rand() % 100;
}

Point2D::Point2D(const float& newx, const float& newy) {
    x = newx;
    y = newy;
}
 void Point2D::setXY(const float& newx, const float& newy){
    x = newx;
    y = newy;
 }

void Point2D::setX(const float& newx){
    x = newx;
}

void Point2D::setY(const float& newy){
    y = newy;
}
float Point2D::getX() const{
    return x;
}

float Point2D::getY() const{
    return y;
}
void Point2D::print(){
    cout << "x = " << x << " y = " << y << endl;
} 
float Point2D::distanceTo(const Point2D& otherPoint2D){
    return sqrt(pow(x - otherPoint2D.x, 2) + pow(y - otherPoint2D.y, 2));
}
