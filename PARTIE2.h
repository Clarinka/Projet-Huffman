/*****************************************************************//**
 * \file   PARTIE2.h
 * \brief  Creation de l'arbre Huffman premiere version.
 *
 * \author Camelia MAHRAZ camelia.mahraz@efrei.net
 * \date   December 2020
 *********************************************************************/




#ifndef PARTIE2_h
#define PARTIE2_h
#include <stdio.h>




/**
* \brief Function to create a simply linked list with its elements from the file text.
* \n Example :
* \code{.c}
* Element* element = occurrence_caractere();
* \endcode
* \return the list, if the List is created.
* \return \c NULL, if the List could not be created.
 *
 * .
 */
Element* occurrence_caractere();



/**
* \brief Function that returns a Huffman tree, from a list of occurrences.
* \return the tree which was created.
*/

Noeud* creation_liste_de_noeud(Element* );

/**
* \brief Function that stores the dictionary from the Huffman tree in a txt file.
* \return nothing it is a void function.
*/

void fichier_texte_arbre_Huffman(Noeud* );

/**
* \brief Function which translates a text into a binary sequence based on a Huffman dictionary.
* \return nothing it is a void function.
*/

void traduction_texte_en_suite_binaire();

/**
* \brief Function that compresses a text file.
* \return nothing it is a void function.
*/

void compression_fichier_texte();


/**
* \brief Function which decompresses a text file from a Huffman tree.
* \return nothing it is a void function.
*/

void decompression_fichier_texte();

#endif /* PARTIE2_h */
