#pragma once
#include "Point2D.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

class Vector{
    public :
        Point2D start;
        Point2D end;
    private:
        Vector();
        Vector(Point2D start, Point2D end);
        Vector(int x1, int y1, int x2, int y2);
        Vector(const Vector& v);
        void Addition(const Vector& v);
        void Multiplication(float scalar);
        bool isEqual(const Vector& v);
};