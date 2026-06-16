#include <iostream>
#include "fichier.hpp"
using namespace std;
int main(){
/*
    Pile A;
    A.Empiler(5);
    A.Empiler(7);
    A.Afficher_Rec();
    Pile B;
    string T[5]={"3","5","+","10","*"};
    
    int a=B.evaluer(T,5);
    cout<< a << endl;
    string c;
    cout << " entrerz un expression infixée:";
    cin>> c;
    Pilestr C;
    int taille;
    string * Tab=C.infixeverssufixe(c,taille);
    cout << " l'expression postfixée :";
    for(int i =0 ; i<taille;i++){
        cout << Tab[i]<<" ";
    }
    cout<<endl;
    Pile D;
    int b=D.evaluer(Tab,taille);
    cout << "le resultat est "  << b<<  endl;
 */
    string k;
    cout<< " entrerz un expression infixée:";
    cin>> k;
    Arbre F(k);
    F.afficher_infixe();
    double Resultat=F.evaluer();
    cout<< " le resultat de l'expresssion est "<< Resultat<<endl;
   
    Arbre A1(new noeud('+',
             new noeud('X'),
              new noeud('X')));
    char V;
    cout<< "entrez la variable ou quelle on calcule la dériver ( X,Y,Z )";
    cin>> V;
    Arbre D1(A1,V);
    D1.afficher_infixe();
    return 0;
   

    
}
  

