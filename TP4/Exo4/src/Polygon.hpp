#pragma once
#include "Point2D.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

class Polygon{
    private : 
        Point2D *points;
        int nbpoints;
    public :
        Polygon();
        Polygon(const Point2D *newPoints, const int& newNbPoints);
        Polygon(const Polygon& newPolygon);
        ~Polygon();
        Point2D* getPoints();
        void addPoint(const Point2D& newPoint);
        int getNbPoints();
        void setPoints(const Point2D *newPoints, const int& newNbPoints);
        void setNbPoints(const int& newNbPoints);
        float getArea();
        void print();
};