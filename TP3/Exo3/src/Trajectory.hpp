#include "Point3D.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

//constexpr size_t NumberOfPoints = 10;
class Trajectory{
    private:
    Point3D *points;
    int NumberOfPoints;
    public:
    Trajectory();
    Trajectory(int NumberOfPoints);
    ~Trajectory();
    void print();
    Point3D & getpoint(const int &n);
    float getTotalDistance();
};
