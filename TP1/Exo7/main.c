#include <stdio.h>
#include <stdlib.h>





//affiche le tableau
void affiche(int **tab, int lgtab){
    for(int i=0; i<lgtab; i++){
        for(int j=0; j<lgtab; j++){
            printf("%3d | ",tab[i][j]);
        }
        printf("\n");
    }
}

int main(){  
    int n;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);
    int ** tab;
    tab = (int **) malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++){
        tab[i] = (int *) malloc(n * sizeof(int));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tab[i][j]=rand()%100;
        }
    }
    
    affiche(tab,n);
    //trie les colones du tableau
    int mini;
    int temp;
    for(int k=0;k<n;++k){
        for(int i=0;i<n;++i){
            mini=i;
            for(int j=i;j<n;++j){
                
                if(tab[j][k]<tab[mini][k]){
                    
                    mini=j;
                    }
            }  
            temp=tab[i][k];
            tab[i][k]=tab[mini][k];
            tab[mini][k]=temp;
    }
    }
    printf("\n");
    affiche(tab,n);
    
    
}