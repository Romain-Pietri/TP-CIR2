#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>



int main(){
    std::ifstream fichier("texte.txt");
    std::string ligne;
    int nbLignes = 0;
    int nbMots = 0;
    int nbLettres = 0;
    int nbtab[26] = {0};
    while(std::getline(fichier, ligne)){

        nbLignes++;
        nbMots += std::count(ligne.begin(), ligne.end(), ' ') + 1;
        nbLettres += ligne.size();
        
        for(int i = 0; i < ligne.size(); i++){
            if(ligne[i] >= 'a' && ligne[i] <= 'z'){
                nbtab[ligne[i] - 'a']++;
            }
            else if(ligne[i] >= 'A' && ligne[i] <= 'Z'){
                nbtab[ligne[i] - 'A']++;
            }
        }
    }
    std::cout << "Nombre de lignes: " << nbLignes << std::endl;
    std::cout << "Nombre de mots: " << nbMots << std::endl;
    std::cout << "Nombre de lettres: " << nbLettres << std::endl;
    for(int i = 0; i < 26; i++){
        std::cout << (char)('a' + i) << ": " << nbtab[i] << std::endl;
    }

    return 0;
}
