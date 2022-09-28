#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int affiche(char * str, char * tab){
    int good=0;
    int nbrest=0;
    for(int i = 0; i < strlen(str); i++){
        good=0;
        for(int j = 0; j < strlen(tab); j++){
            if(str[i] == tab[j]){
                good=1;
                printf("%c", str[i]);
            }
        }
        if(good==0){
            nbrest=1;
            printf("_");
        }

    }
    printf("\n");
    return nbrest;
}

int estla(char c, char * tab, char * str){
    for(int i=0; i<strlen(str); i++){
        if(str[i]==c){
            for(int j=0; j<strlen(tab); j++){
                if(tab[j]==c){
                    return 2;
                }
            }
            return 1;
        }
    }
    return 0;

}




int main(){
    char * str;
    str = (char *) malloc(100 * sizeof(char));
    printf("Entrez le mot a trouver : ");
    scanf("%s", str);
    char c;
    int i = 0;
    

    int length = strlen(str);
    char tab[length];
    int nbreste=0;
    int erreur =0;
    while(erreur<10){
        printf("Entrez une lettre : ");
        scanf(" %c", &c);
        int res = estla(c, tab, str);
        if(res==2){
            printf("Vous avez deja trouve cette lettre\n");
        }
        else if(res==0){
            printf("Cette lettre n'est pas dans le mot\n");
            erreur ++;
            printf("Il vous reste %d erreurs\n", 10-erreur);
        }
        else{
            tab[i]=c;
            i++;
            
        }
        nbreste=affiche(str, tab);
        if(nbreste==0){
            printf("Vous avez trouve le mot\n");
            return 0;
        }
        printf("\n");
    }
    printf("vous avez perdu\n");
    printf("le mot etait : %s\n", str);
}