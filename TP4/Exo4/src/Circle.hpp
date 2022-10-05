#pragma once
#include <iostream>
#include <cstddef>
#include "Shape.hpp"
using namespace std;

class Circle: public Shape{
    private : 
        float radius;
    public :
        Circle();
        Circle(const float newRadius);
        float getRadius();
        void setRadius(float newRadius);
        float getArea();
        float getPerimeter();
        float getAreaMonteCarlo(const int& nbPoints);
};