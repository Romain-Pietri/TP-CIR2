#include <iostream>
#include <iomanip>



int main(){
    //affiche les tables de multiplacation de 1 à 10 alignées à droite
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }
    return 0;
    

}
