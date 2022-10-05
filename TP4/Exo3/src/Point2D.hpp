class Point2D {
private:
    float x, y; // private attributes
public:
    // constuctors
    Point2D(); // fill X Y Z with random values (from 0 to 100)
    Point2D(const float& newx, const float& newy);
    // fill XYZ values
    // Setters and getters
    void setXY(const float& newx, const float& newy);
    void setX(const float& newx);
    void setY(const float& newy);
   
    float getX() const;
    float getY() const;
    // other methods
    void print(); // prints the coordinates of the point
    float distanceTo(const Point2D& otherPoint2D);
};