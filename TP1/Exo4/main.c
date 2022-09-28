/*fichier C*/
#include <stdlib.h>
#include <stdio.h>

int factoriel_for(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

int factoriel_while(int n)
{
    int res = 1;
    int i = 1;
    while (i <= n)
    {
        res *= i;
        i++;
    }
    return res;
}
int factoriel_rec(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factoriel_rec(n - 1);
}

int main()
{
    int n;
    printf("Entrez un nombre : ");
    scanf("%d", &n);
    printf("Factoriel for : %d\n", factoriel_for(n));
    printf("Factoriel while : %d\n", factoriel_while(n));
    printf("Factoriel rec : %d\n", factoriel_rec(n));
    return 0;
}
