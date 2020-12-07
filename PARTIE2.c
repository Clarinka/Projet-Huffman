#include "PARTIE2.h"
#include <stdlib.h>



/* liste contenant chaque caractère présent dans le texte
ainsi que le nombre d’occurrences de ce caractère */
Element* creer_Element(char caractere)
{
    Element* new_element;
    new_element = (Element*)malloc(sizeof(Element));
    new_element->lettre = caractere;
    new_element->occurrence = 1;
    new_element->next = NULL;
    return new_element;

}

void liberer_liste(Element** l)
{
    Element* temp;

    if((*l) == NULL){
        return NULL;
    }
    while((*l) != NULL){
        temp = (*l);
        (*l) = (*l)->next;
        free(temp);
    }
}


/* on a ajouter un maillon à la liste lorqu'il y a un nouveau caractère du texte qui n'est pas encore
dans la liste et on va l'ajouter à la fin comme ça la réference au premier élément n'est pas
modifié */
void ajouter_valeur_liste_fin(Element* l, char caractere)
{
    Element* temp1;
    Element* temp2;
    temp1 = l;

    while(temp1->next != NULL){
        temp1 = temp1->next;
    }

    temp2 = creer_Element(caractere);
    temp1->next = temp2;

}

/* si le caractère est déjà présent dans la liste il n'y a qu'a incrémenter l'occurence du maillon
contenant ce carctère */
void ajouter_un_a_occurence(Element* liste)
{
    liste->occurrence = liste->occurrence + 1;
}


void afficher_Liste(Element* l)
{
    Element* temp;
    temp = l;
    if(l == NULL){
        printf("Liste vide\n");
    }
    else{
        while(temp != NULL){
            printf("%c , %d -> \n",temp->lettre, temp->occurrence);
            temp = temp->next;
        }
    }
    printf("NULL \n");
    liberer_liste(&temp);

}

/* les conditions étant qu'on va regarder tant que la liste n'est pas nulle chaque maillon pour savoir
si le caractère donné est présent :
s'il est dans la liste on appelle la fonction ajouter_un_a_occurence
sinon on appelle ajouter_valeur_liste_fin */
Element* condition_liste_caracteres_occurrences(Element* liste, char caractere)
{
    Element* temp = liste;

    while(temp != NULL){

        if(temp->lettre == caractere){
            ajouter_un_a_occurence(temp);
            return liste;
        }
        else{
            temp = temp->next;
        }
    }

    ajouter_valeur_liste_fin(liste,caractere);
    return liste;
}



Element* occurrence_caractere()
{
    char caractere;
    Element* liste = NULL;
    int i = 0;


    FILE* fichier = NULL;
    fichier = fopen("Alice.txt", "r");

    if(fichier != NULL){
        while((caractere = fgetc(fichier)) != EOF){

            if(i == 0){
                liste = creer_Element(caractere);
                i = i + 1;
            }

            else{
                liste = condition_liste_caracteres_occurrences(liste,caractere);
            }
        }

    }

    fclose(fichier);
    return liste;

}

/* liste contenant des noeuds */
Noeud* creer_noeud_avec_caractere(int occurence, char caractere)
{
    Noeud* new_noeud;
    new_noeud = (Noeud*)malloc(sizeof(Noeud));
    new_noeud->lettre = caractere;
    new_noeud->poids = occurence;
    new_noeud->next = NULL;
    new_noeud->left = NULL;
    new_noeud->right = NULL;
    return new_noeud;
}



int position_min_liste(Element* l)
{
    int position = 1;
    int minimum = l->occurrence;

    if(l==NULL)
    {
        return NULL;
    }
    else{
        Element* temp = l;
        while(temp != NULL)
        {
            if (temp->occurrence < minimum)
            {
                minimum = temp->occurrence;
            }
            temp = temp->next;
        }

        temp = l;
        while(temp->occurrence != minimum){
            position = position + 1;
            temp = temp->next;
        }

    }
    return position;
}


/* supprimer un maillon en fonction de la position dans la liste du maillon à supprimer */
void supprimer_maillon_liste(Element** l, int pos)
{
    if(l == NULL || (*l) == 0 || pos <= 0){return;}

    else{
        Element* temp1 = (*l);
        Element* temp2 = NULL;
        int i = 1;

        if(pos == 1){
            (*l) = (*l)->next;
            free(temp1);
        }

        else if(pos > 1){
            while(temp1->next != NULL && i <= pos){
                if(i == pos){
                    temp2 = temp1->next->next;
                    free(temp1->next);
                    temp1->next = temp2;
                    i = i+1;
                }
                else{
                    i = i +1;
                    temp1 = temp1->next;
                }
            }
            if(temp1->next == NULL){
                free(temp1->next);
                temp1 = NULL;
            }
        }

    }
}

Noeud* création_liste_de_noeud(Element* l)
{
    Noeud* new_noeud = NULL;
    Element* temp = l;
    int position_maillon;
    int i = 1;


    while(temp != NULL){
        position_maillon = position_min_liste(temp);

        while(i != position_maillon){
            i = i + 1;
            temp = temp->next;
        }
        new_noeud = creer_noeud(temp->occurrence,temp->lettre);

    }
}
