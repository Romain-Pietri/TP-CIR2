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
    for (int i = 0; i < NumberOfPoints-; i++) {
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
/*
int main(){
    srand(time(NULL));
    Trajectory t; 
    t.print();
    cout << t.getTotalDistance() << endl;
    return 0;
    
}
*/