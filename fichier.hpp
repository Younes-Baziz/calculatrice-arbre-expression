#ifndef FICHIER_HPP
#define FICHIER_HPP
#include <string>

using namespace std;
class Maillon{
    
        
	int info;
	Maillon *suiv; 
    public:
    Maillon(int v);
    Maillon(int v, Maillon *s);

     friend class Pile;
    

};
class Pile{
    Maillon *tete;
    public:
    Pile();
    ~Pile();
    void Empiler (int x);
    void empiler(string x);
    int depiler();
    bool vider();
    void Afficher_Rec();
    void Afficher_Rec(Maillon * M);
    int evaluer(std::string *T,int n);
    friend class Pilestr;

};
class Maillonstr {
public:
    string info;
    Maillonstr* suiv;

    Maillonstr(string val, Maillonstr* s = nullptr) {
        info = val;
        suiv = s;
    }
};

class Pilestr {
private:
    Maillonstr* tete;
   
public:
    Pilestr() { tete = nullptr; }
    ~Pilestr();
    void Empiler(string x);     
    string Depiler();          
    bool EstVide();             
    string Sommet() ;
     
    public:
    int  priorite(string op);
    bool estAssocDroite(string op);
    string* infixeverssufixe(string expr,int & taille);      
};



class noeud
{
    public:
   char type ;
   char ope ;
   double val ;
   noeud * fg, * fd ;
   noeud(char op, noeud* gauche, noeud* droite);
   noeud(double v);
   noeud(char variable);
   
   
} ;
class Arbre {
    public:
     noeud *racine;
     ~Arbre();
     Arbre();
     Arbre(noeud *n);
     Arbre(string expr);
     Arbre(Arbre& autre, char var);
     void afficher_infixe();
     double evaluer();
     
     
     
     private: 
      void afficher_infixe(noeud * n);
      double evaluer(noeud * n);
      void detruire(noeud *n);
      noeud * clone(noeud *n);
      noeud* derivee(noeud* p , char var);
};
class Maillonoeud {
public:
    noeud* info;
    Maillonoeud* suiv;

    Maillonoeud(noeud * val, Maillonoeud* s = nullptr) ;
        
    
};
class Pilenoeud{
    Maillonoeud * tete ;
    public:
    ~Pilenoeud() ;
    Pilenoeud();
    void Empiler(noeud* n);
    noeud* Depiler();
    bool EstVide();
    noeud * arbrefromsuffixe(string * expr , int taille);
    
};
#endif

