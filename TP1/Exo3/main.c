/*fichier C*/
#include <stdlib.h>
#include <stdio.h>m

char min(char a)
{
    if (a >= 'A' && a <= 'Z')
        return a + 32;
    else
        return a;
}
int main()
{
    char a;
    printf("Entrez une lettre : ");
    scanf("%c", &a);
    printf("La lettre minuscule est : %c\n", min(a));
    return 0;
}
