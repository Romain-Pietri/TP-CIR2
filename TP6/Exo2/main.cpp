#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Fraction{
    private:
        int num;
        int den;
    public:
    bool Isgood(){
        if(this->den==0){
            cout<<"ERROR Denominator is 0"<<endl;
            return false;

        }
        return 1;
    }
    Fraction(int num, int den){
        this->num = num;
        this->den = den;
        if(this->den<0 && this->num<0){
            this->den = -this->den;
            this->num = -this->num;
        }
        if(!this->Isgood()){
            
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
    bool negatif(){
        if(this->num<0 && this->den<0){
            return false;
        }
        if(this->num<0 || this->den<0){
            return true;
        }
        return false;
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
        cout << "denominator:";
        is >> f.den;
        
        }while(!f.Isgood());
        return is;
    }
   
};

/*En vous basant sur la classe fraction et des algorithmes STL,
 écrire un programmequi permet de lire une liste de fractions
 à partir d’un fichier et de les afficher dans l’ordre croissant*/

int main(){
    //ouvrir un fichier 
    ifstream file;
    file.open("fichier.txt");
    vector<Fraction> fractions;
    if(file){
        int num = 0;
        int den = 0;
        string line;
        
        while(getline(file,line)){
            for(int i=0;i<line.length();i++){
                if(line[i]=='/'){
                    num = stoi(line.substr(0,i));
                    den = stoi(line.substr(i+1,line.length()-i));
                    Fraction f(num,den);
                    fractions.push_back(f);
                    
                }
            }
        }
        //fermer le fichier
        file.close();
    }
    else{
        cout<<"Error: file not found"<<endl;
        return 0;
    }
    //trier les fractions
    sort(fractions.begin(),fractions.end());
    //afficher les fractions triées
    cout<<endl;
    for(int i=0;i<fractions.size();++i){
        cout<<fractions[i]<<endl;
    }
    //affiche la somme totale des fractions
    Fraction sum;
    for(int i=0;i<fractions.size();++i){
        sum += fractions[i];
    }
    cout<<endl;
    cout<<"sum: "<<sum<<endl;
    cout<<"Valeurs supprimé:"<<endl;
    for(int i=0;i<fractions.size();++i){
        if(fractions[i].negatif()){
            cout<<fractions[i]<<endl;
            fractions.erase(fractions.begin()+i);  
            i--;    
        }
    }

    cout<<endl;
    for(int i=0;i<fractions.size();++i){
        cout<<fractions[i]<<endl;
    }
    cout<<"val min : "<<*min_element(fractions.begin(),fractions.end())<<endl;
    cout<<"val max : "<<*max_element(fractions.begin(),fractions.end())<<endl;
    cout<<endl;
    //supprimmer les valeurs répétée
    for(int i=0;i<fractions.size();++i){
        for(int j=i+1;j<fractions.size();++j){
            if(fractions[i]==fractions[j]){
                cout<<"suppression de "<<fractions[j]<<endl;
                fractions.erase(fractions.begin()+j);
                j--;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<fractions.size();++i){
        cout<<fractions[i]<<endl;
    }
    return 1;

}