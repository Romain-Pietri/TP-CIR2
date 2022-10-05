#include "Circle.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

Circle::Circle(): Shape() {
    radius = rand() % 100;
}
Circle::Circle(const float newRadius): Shape() {
    radius = newRadius;
}
float Circle::getRadius(){
    return radius;
}
void Circle::setRadius(float newRadius){
    radius = newRadius;
}
float Circle::getArea(){
    return M_PI * pow(radius, 2);
}
float Circle::getPerimeter(){
    return 2 * M_PI * radius;
}
float Circle::getAreaMonteCarlo(const int& nbPoints){
    float area = 0;
    for(int i = 0; i < nbPoints; i++){
        float x = (float)rand() / RAND_MAX;
        float y = (float)rand() / RAND_MAX;
        if(x * x + y * y <= 1){
            area++;
        }
    }
    float approxPi = 4 * area / nbPoints;
    return approxPi*radius*radius;
}

int main(){
    Circle c1;
    cout << "c1.getArea() = " << c1.getArea() << endl;
    cout << "c1.getPerimeter() = " << c1.getPerimeter() << endl;
    cout << "c1.getAreaMonteCarlo(1000000) = " << c1.getAreaMonteCarlo(10000000) << endl;
    return 0;
}