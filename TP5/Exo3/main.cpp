#include <iostream>
#include <cstdlib>
using namespace std;
class Point2D{
    private: 
        float x;
        float y;
    public:
        Point2D(){
            this->x = 0;
            this->y = 0;
        }
        Point2D(float x, float y){
            this->x = x;
            this->y = y;
        }
        Point2D(const Point2D& p){
            this->x = p.x;
            this->y = p.y;
        }
        float getX(){
            return this->x;
        }
        float getY(){
            return this->y;
        }
        void setX(float x){
            this->x = x;
        }
        void setY(float y){
            this->y = y;
        }

        Point2D operator+(const Point2D& p){
            Point2D res;
            res.x = this->x + p.x;
            res.y = this->y + p.y;
            return res;
        }
        Point2D operator-(const Point2D& p){
            Point2D res;
            res.x = this->x - p.x;
            res.y = this->y - p.y;
            return res;
        }
        int operator *(const Point2D& p){
            return this->x * p.x + this->y * p.y;
        }
        Point2D operator |(const Point2D& p){
            Point2D res;
            res.x=(this->x + p.x)/2;
            res.y=(this->y + p.y)/2;
            return res;
        }
        bool operator==(const Point2D& p){
            return this->x == p.x && this->y == p.y;
        }
        bool operator!=(const Point2D& p){
            return !(*this == p);
        }
        friend ostream& operator<<(ostream& os, const Point2D& p){
            os << "(" << p.x << ", " << p.y << ")";
            return os;
        }
        friend istream& operator>>(istream& is, Point2D& p){
            is >> p.x >> p.y;
            return is;
        }

};

int main(){
    Point2D p1(1, 2);
    Point2D p2(3, 4);
    Point2D p3;
    p3 = p1 + p2;
    cout << p3 << endl;
    p3 = p1 - p2;
    cout << p3 << endl;
    cout << p1 * p2 << endl;
    p3 = p1 | p2;
    cout << p3 << endl;
    cout << (p1 == p2) << endl;
    cout << (p1 != p2) << endl;
    cin >> p3;
    cout << p3 << endl;
    return 0;
    
}