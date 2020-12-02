/*****************************************************************//**
 * \file   PARTIE1.h
 * \brief  Conversion caracteres d'un fichier texte en binaire.
 *
 * \author Camelia MAHRAZ camelia.mahraz@efrei.net
 * \date   December 2020
 *********************************************************************/


#ifndef PARTIE1_h
#define PARTIE1_h
#include <stdio.h>
#include <stdlib.h>

/**
* \brief Function to convert a character to bits.
* \return nothing it is a void function.
*/
void convertir_binaire(int*, char*);

/**
 *\brief Function to convert characters via a text file to bits.
* \return nothing it is a void function.
 */
void equivalent_fichier_texte();

/**
* \brief Function to count the number of characters in a text file
* \return number of characters in a text file
*/
int compter_carac_txt();

/**
* \brief Function to count the number of characters in a binary text file
* \return number of characters in a binary text file
*/
int compter_carac_txt_bin();

#endif // PARTIE1_h
