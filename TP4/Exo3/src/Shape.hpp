#pragma once
#include <iostream>
#include <cstddef>
using namespace std;

class Shape{
    private : 
        const int id;
    protected : 
        Shape();
        int color;
        int getID();
    public :
        int getColor();
        void setColor(int newColor);
};