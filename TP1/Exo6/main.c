#include <stdio.h>
#include <stdlib.h>

void affichetab(int *tab, int lgtab){
    for(int i=0; i<lgtab; i++){
        printf("%3d| ",tab[i]);
    }
    printf("\n");
}
void remplir_random(int *tab, int lgtab){
    for(int i=0; i<lgtab; i++){
            tab[i]=rand()%100;
    }
}

int main(){
    int *tab;
    int *tabindice;
    int n;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);
    tab = (int *) malloc(n * sizeof(int));
    remplir_random(tab,n);
    affichetab(tab,n);
    tabindice = (int *) malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        tabindice[i]=-1;
    }
    int min = 101;
    int go=0;
    for(int j =0; j<n;++j){
        for(int i=0; i<n; ++i){
            go=1;
            if(tab[i]<min){
                for(int k=0; k<n;++k){
                    if(tabindice[k]==i){
                        go=0;
                        break;
                    }
                    }
                if(go==1){
                    min=tab[i];
                    tabindice[j]=i;
                }
            }

        } 
        printf("%3d | ",min);
        min=101;
          
    }
}