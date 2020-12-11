#ifndef PARTIE3_h
#define PARTIE3_h
#include<stdio.h>



/**
* \brief Function which, by dichotomous search, adds to an array of nodes an occurrence when the character has already been found, or which adds the node of the character otherwise.
* \return nothing it is a void function.
*/
void ajout_occurrence();


/**
* \brief Function that sorts an array of nodes based on occurrences.
* \return nothing it is a void function.
*/
void trier_tab_noeud(Noeud );

/**
* \brief Function which, using two queues, creates the Huffman tree from an array of nodes sorted by occurrences.
* \return nothing it is a void function.
*/
void creer_Huffman_pile(Queue* , Queue* , Noeud );

/**
* \brief Function that organizes the nodes in an AVL according to the order of the characters present.
* \return the first node of the tree.
*/
Noeud* org_noeuds_AVL(Noeud*);


/**
* \brief Function which compresses a text file in an optimized way.
* \return nothing it is a void function.
*/
void compression_texte();



/**
* \brief Function which decompresses a text file from a Huffman dictionary file.
* \return nothing it is a void function.
*/
void decompression_texte();



#endif 
