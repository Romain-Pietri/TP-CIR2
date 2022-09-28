#include "Trajectory.hpp"

#include <iostream>
using namespace std;


Trajectory::Trajectory(){
    NumberOfPoints = rand()%100;
    points = new Point3D[NumberOfPoints];
    
}
Trajectory::Trajectory(int n) {
    points = new Point3D[n];
    NumberOfPoints = n;
    
}
Trajectory::~Trajectory() {
    delete[] points;

}

void Trajectory::print() {
    for (int i = 0; i < NumberOfPoints; i++) {
        points[i].print();
    }
}
Point3D & Trajectory::getpoint(const int &n) {
    return points[n];
}
float Trajectory::getTotalDistance() {
    float totalDistance = 0;
    for (int i = 0; i < NumberOfPoints-1; i++) {
        totalDistance += points[i].distanceTo(points[i + 1]);
    }
    return totalDistance;
}


/*
void Trajectory::print(){
    for (int i = 0; i < NumberOfPoints; ++i)
    {
        points[i].print();
    }
    
}

Point3D & Trajectory::getpoint(const int &n){
    return points[n];
}


float Trajectory::getTotalDistance(){
    float total = 0;
    for (int i = 0; i < NumberOfPoints-1; i++)
    {
        total += points[i].distanceTo(points[i+1]);
    }
    return total;
}
*/

int main(){
    srand(time(NULL));
    Trajectory t(3); 
    //trace une droite
    t.getpoint(0).setX(0);
    t.getpoint(0).setY(0);
    t.getpoint(0).setZ(0);
    t.getpoint(1).setX(1);
    t.getpoint(1).setY(1);
    t.getpoint(1).setZ(1);
    t.getpoint(2).setX(2);
    t.getpoint(2).setY(2);
    t.getpoint(2).setZ(2);

    t.print();
    cout << t.getTotalDistance() << endl;
    return 0;
    
}
