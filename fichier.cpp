#include <iostream>
#include "fichier.hpp"
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
Maillon::Maillon(int V)
{
	info = V;
	suiv = nullptr;
}
Maillon::Maillon(int v ,Maillon *s){
    info=v;
    suiv=s;
}
Pile::Pile(){
    tete=NULL;
}

void Pile::Empiler(int x){
 tete=new Maillon(x,tete);
}
bool Pile::vider(){
    if(tete==nullptr){
        return true;
    }
    return false;
}
int Pile::depiler(){
    if(vider()){
        cout<<"la pile est vide"<<endl;
        return 0;
    }
 
     Maillon *temp=tete;
     int v = temp->info;
     tete=tete->suiv;
     delete temp;
     return v ;
     
}
Pile::~Pile(){
    while(!vider()) depiler();
}
void Pile::Afficher_Rec()
{
  Afficher_Rec(tete);
  cout << endl;
}

void Pile::Afficher_Rec(Maillon * M)
{
  if (M == nullptr){   return;}
 
  cout << M -> info << "  ";
  Afficher_Rec(M -> suiv);
}
int Pile::evaluer(string *T, int n){
    for(int i = 0 ; i<n ;i++){
        if(T[i]!="+"&&T[i]!="-"&&T[i]!="*"&&T[i]!="/"){
            int x= atoi(T[i].c_str());
            Empiler(x);
        }else{
          if (this->vider()) {
                cout << "Erreur : pile vide avant depilement (a) !" <<endl;
                return 0;
            }
          int a=this->depiler();
            if (this->vider()) {
            cout << "Erreur : pile vide avant depilement (b) !" <<endl;
                return 0;
            }
          int b =this->depiler();
          int resultat;
    
            if (T[i] == "+") {
                resultat = a + b;
            }
            else if (T[i] == "-") {
                resultat = b-a;
            }
            else if (T[i] == "*") {
                resultat = a * b;
            }
            else if (T[i] == "/") {
                if (a== 0) {cout<<"Division par zéro !"<<endl; return 0;}
                resultat = b / a;
            }

           
            Empiler(resultat);
        
        }
        
      }
       if (this->vider()) {
        cout << "pile vide à la fin." <<endl;
        return 0;
    }
      return this->depiler();

}
int Pilestr:: priorite(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool Pilestr::estAssocDroite(string op) {
    return op == "^";
}
void Pilestr::Empiler(string x) {
    Maillonstr* nouveau = new Maillonstr(x, tete);
    tete = nouveau;
}

string Pilestr::Depiler() {
    if (tete == nullptr) {
        cout << "Erreur : pile vide\n";
        return "";
    }
    Maillonstr* temp = tete;
    string val = temp->info;
    tete = tete->suiv;
    delete temp;
    return val;
}

bool Pilestr::EstVide() {
    return this->tete == nullptr;
}
string Pilestr::Sommet() {
      if (tete == nullptr) return "";
     return this->tete->info;
  }
Pilestr::~Pilestr(){
    while(!EstVide()) Depiler();
}
string *Pilestr::infixeverssufixe(string expr,int & taille){
  
   string s1;
    for(int i =0 ; i<expr.size() ; i++) {
        if (expr[i] == '(' || expr[i] == ')' || expr[i] == '+' || expr[i] == '-' || expr[i]== '*' || expr[i] == '/' || expr[i] == '^') {
            s1 += ' ';
            s1 += expr[i];
            s1 += ' ';
        } else {
            s1 += expr[i];
        }
    }
    int n=0;;
    istringstream ss1(s1);
    string h;
    
    while (ss1 >> h) {
       n++;
    }
    istringstream ss2(s1);
    string* T = new string[n];
    for (int i = 0; i < n; i++) {
        ss2>>T[i];
    }
  string *sortie=new string [n];
  int index=0;
  for(int i =0 ; i< n ;i++){
   if(T[i]!="*" and T[i]!="-" and T[i]!="+" and T[i]!="/" and T[i] != "^" and  T[i] != "(" and T[i] != ")"){
       sortie[index++]=T[i];
     
    }else if(T[i]=="(") {
      Empiler(T[i]);
     }
     else if(T[i]==")"){
       while(!EstVide()&& Sommet() != "("){
                sortie[index++]=Depiler();
            }
             if (!EstVide()) Depiler(); 
           
        }
      else{ 
      while (!EstVide() && Sommet() != "(" &&  (priorite(Sommet()) > priorite(T[i]) || (priorite(Sommet()) == priorite(T[i]) && !estAssocDroite(T[i])))) {
                sortie [index++] = Depiler();
            }
           Empiler(T[i]);
      }
  }
    while (!EstVide()) {
        sortie[index++] = Depiler();
    }

    taille=index;
    
    return sortie;
  
}
Maillonoeud::Maillonoeud(noeud * val ,Maillonoeud *s){
    info =val;
    suiv=s;
}
Pilenoeud::Pilenoeud(){
    tete =NULL;
    
}
Pilenoeud ::~Pilenoeud(){
    while(!EstVide()){
        Depiler();
    }
}
void Pilenoeud:: Empiler(noeud* n) {
        tete = new Maillonoeud(n, tete);
}
noeud* Pilenoeud::Depiler() {
        if (EstVide()) return nullptr;
        Maillonoeud* temp = tete;
        noeud* val = temp->info;
        tete = tete->suiv;
        delete temp;
        return val;
    }
bool Pilenoeud:: EstVide() {
        return tete == nullptr;
}
noeud::noeud(double v){
  type='f';
  ope='\0';
  val = v;
  fg=NULL;
  fd=NULL;
}
noeud::noeud(char variable) {
    type = 'f';      
    ope = variable;  
    val = 0;        
    fg = fd = nullptr;
}

noeud::noeud(char op, noeud* gauche, noeud* droite) {
        type = 'o';
        ope = op;
        fg = gauche;
        fd = droite;
}
Arbre::Arbre(){
    racine=NULL;
}
noeud* Pilenoeud:: arbrefromsuffixe(string * expr , int taille){
    for (int i = 0; i < taille; ++i) {
        if (expr[i] != "+" && expr[i] != "-" && expr[i] != "*" && expr[i] != "/" && expr[i] != "^") {
            
          Empiler(new noeud(std::stod(expr[i])));
        } else {
            
            noeud* droite = Depiler();
            noeud* gauche = Depiler();
            Empiler(new noeud(expr[i][0], gauche, droite));
        }
    }
    return Depiler();
}
Arbre::Arbre(string expr){
    Pilestr A;
    int taille;
    string * T=A.infixeverssufixe(expr, taille);
    Pilenoeud B;
    racine=B.arbrefromsuffixe(T,taille);
}
void Arbre::afficher_infixe(noeud * n){
    if(n==NULL){ 
        return ;
    }
    if(n->type=='f'){
         cout << n->val;
    }else{
        cout<<"(";
        afficher_infixe(n->fg);
        cout<<n->ope;
        afficher_infixe(n->fd);
        cout<<")";
    }
}
void Arbre::afficher_infixe(){
    afficher_infixe(racine);
}
double Arbre::evaluer(noeud *n){
   if (n->type == 'f') {
        return n->val;
    }

    double a = evaluer(n->fg);
    double b = evaluer(n->fd);

    if (n->ope == '+') {
        return a + b;
    }
    else if (n->ope == '-') {
        return a - b;
    }
    else if (n->ope == '*') {
        return a * b;
    }
    else if (n->ope == '/') {
        if (b == 0) {
            cout << "Erreur : division par zéro !" << endl;
            return 0;
        }
        return a / b;
    }
    else if (n->ope == '^') {
        return pow(a, b);
    }

   
    return 0;
}

double Arbre::evaluer(){
    if(racine==NULL){
        return 0;
    }
    return evaluer(racine);
}
void Arbre::detruire(noeud *n){
    if(n==NULL){
        return ;
    }
        detruire(n->fg);
        detruire(n->fd);
    delete n;
}
Arbre::~Arbre(){
    detruire(racine);
}
Arbre::Arbre(noeud * n){
    racine=n;
}
Arbre::Arbre(Arbre& autre, char var){
    this->racine=derivee(autre.racine,var);
}
noeud* Arbre:: clone(noeud* n) {
    if (!n) return nullptr;
    noeud* copie = new noeud(*n);
    copie->fg = clone(n->fg);    
    copie->fd = clone(n->fd);     
    return copie;
}
noeud * Arbre::derivee(noeud * p , char var){
  if(p==nullptr){
        return nullptr;
    } 
    if(p->type=='f'){
       if(p->ope==var){
            return new noeud(1.0);
        }else  if (p->ope == 'X' || p->ope == 'Y' || p->ope == 'Z'){
           return new noeud(0.0); 
        }else{
            return new noeud(0.0);
        }
    }else{
         noeud* u=p->fg;
         noeud * v=p->fd;
         noeud *du =derivee(u,var);
         noeud *dv=derivee(v,var);
        switch(p->ope){
            case '+':
            return new noeud('+',du,dv); 
            case '-':
            return new noeud('-',du,dv);
            case'*':
               return new noeud('+',new noeud('*',du,clone(v)),new noeud('*',clone(u),dv));
            case'/':
                   return new noeud('/',
                                    new noeud('-',
                                          new noeud('*',du,clone(v)),new noeud('*',clone(u),dv)),new noeud('^',clone(v),new noeud(2.0)));
                     
            case '^':
               if(v->type=='f'&&( v->ope!='X' && v->ope!='Y' && v->ope!='Z')){
                   double n=v->val;
                   return new noeud('*',new noeud('*',new noeud(n),du),new noeud('^',clone(u),new noeud(n-1.0)));
               }
               
        }
    }
    return nullptr;
    
}
    
