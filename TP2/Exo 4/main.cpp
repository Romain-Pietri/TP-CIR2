#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int width;
    public:
        int setLength(int l){
            if(l>0 && l<10){length = l; return 1;}
            else return 0;
        }
        int setWidth(int w){
            if(w>0 && w<10){width = w; return 1;}
            else return 0;
        }
        int getLength(){
            return length;
        }
        int getWidth(){
            return width;
        }
        int getArea(){
            return length * width;
        }
        int getPerimeter(){
            return 2 * (length + width);
        }
        void print(){
            cout << "Length: " << length << endl;
            cout << "Width: " << width << endl;
            cout << "Area: " << getArea() << endl;
            cout << "Perimeter: " << getPerimeter() << endl;
        }
        void drawArea(const char& pattern){
            for(int i = 0; i < width; i++){
                for(int j = 0; j < length; j++){
                    cout << pattern<< " ";
                }
                cout << endl;
            }
        }
        void drawPerimeter(const char& pattern){
            for(int i = 0; i < width; i++){
                for(int j = 0; j < length; j++){
                    if(i == 0 || i == width - 1 || j == 0 || j == length - 1){
                        cout << pattern<< " ";
                    }else{
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }
};

int main(){
    Rectangle r;
    int length, width;
    bool valid = false;
    char pattern;
    while(valid==false){
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
        valid = r.setLength(length) && r.setWidth(width);
        if(valid==false)cout << "Invalid input!" << endl;
    }
    cout << "Enter pattern: ";
    cin >> pattern;
    cout <<endl;
    r.print();
    r.drawArea(pattern);
    cout << endl;
    r.drawPerimeter(pattern);
    return 0;
}
