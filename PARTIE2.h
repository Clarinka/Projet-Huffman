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

/**
 * \brief Function to create an element of a simply linked list with a letter and its occurrence.
* \n Example :
* \code{.c}
* Element* element = creer_Element();
* \endcode
* \return the first Element's pointer, if the Element is created.
* \return \c NULL, if the Element could not be created.
*/
Element* creer_Element(char);

/**
 * \brief Function to add an element at the end of a simply linked list with a letter and its occurrence.
* \n Example :
* \code{.c}
*
* \endcode
* \return nothing it's a void function.
* \
 * .
 */
void ajouter_valeur_liste_fin(Element*, char);


/**
 *\brief Function which increment the occurrence of the given character in a simply linked list.
* \return nothing it is a void function.
 */

void ajouter_un_a_occurence(Element*);

/**
 * \brief Function to display the elements of the simply linked list.
* \n Example :
* \code{.c}
*
* \endcode
* \return nothing it's a void function.

 *
 * .
 */
void afficher_Liste(Element*);


/**
* \brief Function to free memory of a simply linked list.
* \n Example :
* \code{.c}
*
* \endcode
* \return nothing it is a void function.
*/
void liberer_liste(Element**);

/**
*\brief Function which checks if the character exists and if so how to add it in the simply linked list and else increment the occurrence.
*       \n Example :
*       \code{.c}
*       if(temp->lettre == caractere){
*            ajouter_un_a_occurence(temp);
*            return liste;}
*       \endcode
* \return the first Element's pointer, if the Element is created.
* \return \c NULL, if the Element is empty.
*/

Element* condition_liste_caracteres_occurrences(Element*, char);
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
* \brief Function which create a node.
* \n Example :
* \code{.c}
* Noeud* noeud = creer_noeud();
* \endcode
* \return the node which was created.
*/
Noeud* creer_noeud(int, char);

/**
*\brief Function which checks the smallest occurrence of the simply linked list.
* \n Example :
*       \code{.c}
*       if (temp->occurrence < minimum)
*            {
*                minimum = temp->occurrence;
*            }
*       \endcode
* \return the minimum if it exists.
* \return \c NULL, if the Element is empty.
*/

int position_min_liste(Element*);


/**
* \brief Function which deletes a link according to the position in the list of the link to delete.
* \n Example :
*       \code{.c}
*       if(temp1->next == NULL){
*                free(temp1->next);
*                temp1 = NULL;
*            }
*       \endcode
* \return nothing it is a void function.
*/

void supprimer_maillon_liste(Element**, int);



#endif /* PARTIE2_h */
