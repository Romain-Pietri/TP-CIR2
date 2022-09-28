//crrer class quadrupede chat et chien
//crrer class quadrupede chat et chien
#include <iostream>
#include <string>
using namespace std;
class Quadrupede{
    
        
    public:
        string nom;
        
        Quadrupede(string nom){
            this->nom = nom;
        }
        void setNom(string nom){
            this->nom = nom;
        }
        string getNom(){
            return this->nom;
        }


};
class Chien:public Quadrupede{
    public:
        Chien(string nom):Quadrupede(nom){
            this->nom = nom;
        }
        void aboyer(){
            cout << "wouf wouf" << endl;
        }
};
class Chat:public Quadrupede{
    public:
        Chat(string nom):Quadrupede(nom){
            this->nom = nom;
        }
        void miauler(){
            cout << "miaou" << endl;
        }
};
int main(){
    Chien chien("chien");
    Chat chat("chat");
    chien.aboyer();
    chat.miauler();
    return 0;
}