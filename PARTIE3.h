#ifndef PARTIE3_h
#define PARTIE3_h
#include<stdio.h>
#include<stdlib.h>

void ajout_occurrence(int*,Noeud*);

void trier_tab_noeud(int*);

void creer_Huffman_pile(Queue*, Queue*, int*);

Noeud* org_noeuds_AVL(Noeud*);

void compression_texte();

void decompression_texte();



#endif 
