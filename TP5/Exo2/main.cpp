#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction{
    private:
        int num;
        int den;
    public:
    bool Isgood(){
        return this->den != 0;
    }
    Fraction(int num, int den){
        this->num = num;
        this->den = den;
        if(!this->Isgood()){
            cout << "Error: denominator is 0" << endl;
            exit(1);
        }
    }
    Fraction(){
        this->num = 0;
        this->den = 1;
    }
    Fraction(const Fraction& f){
        this->num = f.num;
        this->den = f.den;
        if(!this->Isgood()){
            cout << "Error: denominator is 0" << endl;
            exit(1);
        }
    }
    
    int getNum(){
        return this->num;
    }
    int getDen(){
        return this->den;
    }
    void setNum(int num){
        this->num = num;
    }
    void setDen(int den){
        this->den = den;
        if(!this->Isgood()){
            cout << "Error: denominator is 0" << endl;
            exit(1);
        }
    }
    void print(){
        cout << this->num << "/" << this->den << "\n"<< endl;
    }
    Fraction operator+(const Fraction& f){
        Fraction res;
        res.num = this->num * f.den + this->den * f.num;
        res.den = this->den * f.den;
        return res;
    }
    Fraction operator-(const Fraction& f){
        Fraction res;
        res.num = this->num * f.den - this->den * f.num;
        res.den = this->den * f.den;
        return res;
    }
    Fraction operator*(const Fraction& f){
        Fraction res;
        res.num = this->num * f.num;
        res.den = this->den * f.den;
        return res;
    }
    Fraction operator/(const Fraction& f){
        Fraction res;
        res.num = this->num * f.den;
        res.den = this->den * f.num;
        return res;
    }
    Fraction operator+=(const Fraction& f){
        this->num = this->num * f.den + this->den * f.num;
        this->den = this->den * f.den;
        return *this;
    }
    Fraction operator-=(const Fraction& f){
        this->num = this->num * f.den - this->den * f.num;
        this->den = this->den * f.den;
        return *this;
    }
    Fraction operator*=(const Fraction& f){
        this->num = this->num * f.num;
        this->den = this->den * f.den;
        return *this;
    }
    Fraction operator/=(const Fraction& f){
        this->num = this->num * f.den;
        this->den = this->den * f.num;
        return *this;
    }
    Fraction operator++(){
        this->num += this->den;
        return *this;
    }
    Fraction operator++(int){
        Fraction res = *this;
        this->num += this->den;
        return res;
    }
    Fraction operator--(){
        this->num -= this->den;
        return *this;
    }
    Fraction operator--(int){
        Fraction res = *this;
        this->num -= this->den;
        return res;
    }
    bool operator==(const Fraction& f){
        return this->num * f.den == this->den * f.num;
    }
    bool operator!=(const Fraction& f){
        return this->num * f.den != this->den * f.num;
    }
    bool operator<(const Fraction& f){
        return this->num * f.den < this->den * f.num;
    }
    bool operator>(const Fraction& f){
        return this->num * f.den > this->den * f.num;
    }
    bool operator<=(const Fraction& f){
        return this->num * f.den <= this->den * f.num;
    }
    bool operator>=(const Fraction& f){
        return this->num * f.den >= this->den * f.num;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f){
        os << f.num << "/" << f.den;
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f){
        do{
        cout<<endl;
        cout<<"numerator: ";
        is >> f.num;
        cout<<"denominator: ";
        is >> f.den;
        return is;
        }while(f.Isgood());

    }
   
};

int main(){
    Fraction f1(1,2);
    Fraction f2(1,3);
    cout<<"f1 = ";
    f1.print();
    cout<<"f2 = ";
    f2.print();

    Fraction f3;
    cout<<"f3=f1+f2"<<endl;
    f3 = f1 + f2;
    f3.print();
    cout<<"f3=f1-f2"<<endl;
    f3 = f1 - f2;
    f3.print();
    cout<<"f3=f1*f2"<<endl;
    f3 = f1 * f2;
    f3.print();
    cout<<"f3=f1/f2"<<endl;
    f3 = f1 / f2;
    f3.print();
    cout<<"f3+=f1"<<endl;
    f3 += f1;
    f3.print();
    cout<<"f3-=f1"<<endl;
    f3 -= f1;
    f3.print();
    f3 *= f1;
    cout<<"f3*=f1"<<endl;
    f3.print();
    f3 /= f1;
    cout<<"f3/=f1"<<endl;
    f3.print();
    f3++;
    cout<<"f3++"<<endl;
    f3.print();
    f3--;
    cout<<"f3--"<<endl;
    f3.print();
    f3 = ++f1;
    cout<<"f3=++f1"<<endl;
    f3.print();
    f3 = --f1;
    cout<<"f3=--f1"<<endl;
    f3.print();
    cout<<"f3=f1++"<<endl;
    f3 = f1++;
    f3.print();
    f3 = f1--;
    cout<<"f3=f1--"<<endl;
    f3.print();
    cout<<"\n\nTeste des operateurs de comparaison"<<endl;
    f1.print();
    f2.print();
    if(f1 == f2){
        cout << "f1 == f2" << endl;
    }
    if(f1 != f2){
        cout << "f1 != f2" << endl;
    }
    if(f1 < f2){
        cout << "f1 < f2" << endl;
    }
    if(f1 > f2){
        cout << "f1 > f2" << endl;
    }
    if(f1 <= f2){
        cout << "f1 <= f2" << endl;
    }
    if(f1 >= f2){
        cout << "f1 >= f2" << endl;
    }
    cout<<"\n\nTeste des operateurs de flux"<<endl;
    cout<<"f1 = ";
    cin>>f1;
    cout<<"f2 = ";
    cin>>f2;
    cout<<"f1 = ";
    cout<<f1<<endl;
    cout<<"f2 = ";
    cout<<f2<<endl;
    if(f1 == f2){
        cout << "f1 == f2" << endl;
    }
    else cout << "f1 != f2" << endl;
    return 0;
}