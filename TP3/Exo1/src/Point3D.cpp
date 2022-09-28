#include "Point3D.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Point3D::Point3D() {
    srand(time(NULL));
    x = rand() % 100;
    y = rand() % 100;
    z = rand() % 100;

}
Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}
void Point3D::setX(const float& newx) {
    x = newx;
}
void Point3D::setY(const float& newy) {
    y = newy;
}
void Point3D::setZ(const float& newz) {
    z = newz;
}
float Point3D::getX() const {
    return x;
}
float Point3D::getY() const {
    return y;
}
float Point3D::getZ() const {
    return z;
}
void Point3D::print() {
    std::cout << "X: " << x << " Y: " << y << " Z: " << z << std::endl;
}
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float otherX = otherPoint3D.getX();
    float otherY = otherPoint3D.getY();
    float otherZ = otherPoint3D.getZ();
    return sqrt(pow((x - otherX), 2) + pow((y - otherY), 2) + pow((z - otherY), 2));
}

/*
int main(){
    Point3D p1;
    Point3D p2(1,2,3);
    Point3D p3;
    p3.setXYZ(4,5,6);
    p3.print();
    p3.setX(7);
    p3.setY(8);
    p3.setZ(9);
    p3.print();
    cout<<endl;
    p1.print();
    p2.print();
    
    cout << p1.distanceTo(p2) << endl;
}