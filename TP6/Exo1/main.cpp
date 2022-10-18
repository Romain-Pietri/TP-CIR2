#include <iostream>
#include <set>
using namespace std;
int main(){
    int a[]={7,4,9,1,3,4,8,2,7,5,3,6,10,4,8,10,1,2};//on creer un tableau
    set <int> s(&a[0],&a[17]);//on cree un set (CA TRIE AUTOMATIQUEMENT C FUN)
    set<int>::iterator p=s.begin();//ON init un iterateur
    while(p!=s.end())cout<<*p++<<" ";//on parcourt le set et on affiche
    return 0;
}