#include "Polygon.hpp"
#include <iostream>
using namespace std;

Polygon::Polygon(){
    nbpoints = 0;
    points = new Point2D[nbpoints];
}
Polygon::Polygon(const Point2D *newPoints, const int& newNbPoints){
    nbpoints = newNbPoints;
    points = new Point2D[nbpoints];
    for(int i = 0; i < nbpoints; i++){
        points[i] = newPoints[i];
    }
}
Polygon::Polygon(const Polygon& newPolygon){
    nbpoints = newPolygon.nbpoints;
    points = new Point2D[nbpoints];
    for(int i = 0; i < nbpoints; i++){
        points[i] = newPolygon.points[i];
    }
}
Polygon::~Polygon(){
    delete[] points;
}
Point2D* Polygon::getPoints(){
    return points;
}
void Polygon::addPoint(const Point2D& newPoint){
    Point2D *newPoints = new Point2D[nbpoints + 1];
    for(int i = 0; i < nbpoints; i++){
        newPoints[i] = points[i];
    }
    newPoints[nbpoints] = newPoint;
    delete[] points;
    points = newPoints;
    nbpoints++;
}
int Polygon::getNbPoints(){
    return nbpoints;
}
void Polygon::setPoints(const Point2D *newPoints, const int& newNbPoints){
    delete[] points;
    nbpoints = newNbPoints;
    points = new Point2D[nbpoints];
    for(int i = 0; i < nbpoints; i++){
        points[i] = newPoints[i];
    }
}
void Polygon::setNbPoints(const int& newNbPoints){
    nbpoints = newNbPoints;
}
float Polygon::getArea(){
    float area = 0;
    for(int i = 0; i < nbpoints-1; i++){
        area += points[i].getX() * points[(i + 1) % nbpoints].getY() - points[(i + 1) % nbpoints].getX() * points[i].getY();
    }
    return area / 2;
}
