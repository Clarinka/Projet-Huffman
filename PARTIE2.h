#ifndef PARTIE2_h
#define PARTIE2_h
#include <stdio.h>


typedef struct Element
{
    int occurrence;
    char lettre;
    struct Element* next;

}Element;

typedef struct Noeud
{
    int poids;
    char lettre;
    struct Noeud* next;
    struct Noeud* left;
    struct Noeud* right;

}Noeud;


Element* creer_Element(char );
void ajouter_valeur_liste_fin(Element* ,char );
void ajouter_un_a_occurence(Element* );
void afficher_Liste(Element* );
void liberer_liste(Element** );
Element* condition_liste_caracteres_occurrences(Element* , char );
Element* occurrence_caractere();
Noeud* creer_noeud(int , char );
int position_min_liste(Element* );
void supprimer_maillon_liste(Element** , int );



#endif /* PARTIE2_h */
