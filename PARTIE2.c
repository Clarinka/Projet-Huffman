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

void liberer_liste_de_noeuds(Noeud** arbre)
{
    Noeud* temp;

    if((*arbre) == NULL){
        return NULL;
    }
    while((*arbre) != NULL){
        temp = (*arbre);
        (*arbre) = (*arbre)->next;
        free(temp);
    }
}





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




void ajouter_un_a_occurence(Element* liste)
{
    liste->occurrence = liste->occurrence + 1;
}





void afficher_Liste(Element* l)
{
    Element* temp;
    temp = l;
    if(l == NULL){
        printf("Liste vide : ");
    }
    else{
        while(temp != NULL){
            printf("%c , %d -> ",temp->lettre, temp->occurrence);
            temp = temp->next;
        }
    }
    printf("NULL \n");
    liberer_liste(&temp);
}






// condition pour qu'on ajout à liste un maillon contenant un nouveau caractère
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






// création de la liste contenant chaque caractère présent dans le texte ainsi que le nombre d’occurrences de ce caractère
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
Noeud* creer_noeud(int poids, char caractere)
{
    Noeud* new_noeud;
    new_noeud = (Noeud*)malloc(sizeof(Noeud));
    new_noeud->lettre = caractere;
    new_noeud->poids = poids;
    new_noeud->next = NULL;
    new_noeud->left = NULL;
    new_noeud->right = NULL;
    return new_noeud;
}




int min_liste(Element* l)
{
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

    }
    return minimum;
}






int position_min_liste(Element* l, int minimum)
{
    int position = 1;

    if(l==NULL)
    {
        return NULL;
    }
    else{
        Element* temp = l;
        while(temp->occurrence != minimum){
            position = position + 1;
            temp = temp->next;
        }

    }
    return position;
}





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
                if((i+1) == pos){
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




void afficher_Liste_de_noeuds(Noeud* arbre)
{
    Noeud* temp;
    temp = arbre;
    int i = 1;

    if(arbre == NULL){
        printf("Liste vide : ");
    }
    else{
        while(temp != NULL){
            if(temp->right != NULL){
                printf("parent %d : %d  ,enfant 1 : %c , %d ,enfant 2 : %c , %d ->\n",i, temp->poids,temp->left->lettre, temp->left->poids, temp->right->lettre, temp->right->poids);
                temp = temp->next;
                i = i + 1;
            }
            else{
                printf("parent %d : %d  ,enfant 1 : %c , %d ,enfant 2 : NULL ->\n",i, temp->poids,temp->left->lettre, temp->left->poids);
                temp = temp->next;
                i = i + 1;
            }

        }
    }
    printf("NULL \n");
    liberer_liste_de_noeuds(&temp);
}





Noeud* creation_liste_de_noeud(Element* l,int poids_precedent)
{
    Noeud* noeud_1 = NULL;
    Noeud* noeud_2 = NULL;
    Noeud* noeud_3 = NULL;
    Element* temp = l;
    int position_maillon;
    int minimum_liste_1, minimum_liste_2;
    int i = 1;


    while(temp != NULL){

        // on récupère le premier maillon ayant le minimum d'occurrences
        minimum_liste_1 = min_liste(temp);
        position_maillon = position_min_liste(temp,minimum_liste_1);

        while(i != position_maillon){
            i = i + 1;
            temp = temp->next;
        }

        noeud_1 = creer_noeud(temp->occurrence,temp->lettre);
        // après récupération et avec ses valeurs stockés dans un noeud on le supprime
        supprimer_maillon_liste(&l,position_maillon);
        temp = l;
        i = 1;



        // si liste n'est pas vide on peut regarder s'il y a un autre minimum = au premier minimum
        if (temp != NULL){

            minimum_liste_2 = min_liste(temp);

            // si le nouveau minimum de la liste est > au premier => on le prend pas en compte
          /*  if(minimum_liste_2 == 0 || (minimum_liste_2 != 0 && minimum_liste_1 < minimum_liste_2)){

                noeud_3 = creer_noeud(noeud_1->poids + poids_precedent, 0);
                noeud_3->left = noeud_1;
                poids_precedent = noeud_3->poids;
            }*/


            // on fait la même chose avec le deuxième maillon
          //  else if(minimum_liste_2 != 0 && minimum_liste_1 == minimum_liste_2){

                position_maillon = position_min_liste(temp,minimum_liste_2);

                while(i != position_maillon){
                    i = i + 1;
                    temp = temp->next;
                }


                noeud_2 = creer_noeud(temp->occurrence,temp->lettre);
                supprimer_maillon_liste(&l,position_maillon);
                temp = l;

                noeud_3 = creer_noeud(noeud_1->poids + noeud_2->poids + poids_precedent, NULL);
                noeud_3->right = noeud_1;
                noeud_3->left = noeud_2;
                poids_precedent = noeud_3->poids;

         //  }


        }

        /* si elle est vide apres avoir supprimer le dernier maillon le poids du parent ne prend que en compte
        l'addition des poids précédants et le poids du dernier maillon */
        else{
            noeud_3 = creer_noeud(noeud_1->poids + poids_precedent, 0);
            noeud_3->left = noeud_1;
            poids_precedent = noeud_3->poids;
        }


        noeud_3->next = creation_liste_de_noeud(l,poids_precedent);
        return noeud_3;
    }

}

void inverser_liste(struct Noeud **debut_arbre)
{

    Noeud* curseur = *debut_arbre;
    Noeud* noeud_preced = NULL;
    Noeud* noeud_suiv = NULL;

    while (curseur != NULL) {
        noeud_suiv = curseur->next;
        curseur->next = noeud_preced;
        noeud_preced = curseur;
        curseur = noeud_suiv;
    }

    *debut_arbre = noeud_preced;
}




void fichier_texte_arbre_Huffman(Noeud* arbre)
{
    FILE* fichier_dico =NULL;
    char caractere;
    Noeud* temp = arbre;
    int i = 1;
    char tableau[1000000];

    fichier_dico = fopen("Dico.txt", "r+");

    if(temp != NULL){

    if(temp->left != NULL){
        caractere = temp->left->lettre;
        tableau[0] = '0';
        fprintf(fichier_dico,"%c : %c \n",caractere, tableau[0]);
    }


    if(temp->right != NULL){
        caractere = temp->right->lettre;
        tableau[0] = '1';
        tableau[i] = '0';
        fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
        tableau[i] = '1';
        i = i + 1;
        temp = temp->next;

        while(temp != NULL){

      /*  if(temp->left != NULL){
            caractere = temp->left->lettre;
            tableau[i] = '0';
            fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
           // tableau[i] = '1';
            i = i + 1;
        }

        if(temp->right != NULL){
            caractere = temp->right->lettre;
            tableau[i] = '1';
            fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
            //tableau[i] = '0';
            i = i + 1;
        }*/
        caractere = temp->left->lettre;
        tableau[i] = '0';
        fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
       /* tableau[i] = '1';
        i = i + 1;*/
        caractere = temp->right->lettre;
        tableau[i] = '1';
        fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
        //tableau[i] = '0';
        i = i + 1;

        temp = temp->next;
        }

    }
    else{

    tableau[0] = '1';
    temp = temp->next;
    while(temp != NULL){

        //if(temp->left != NULL){
            caractere = temp->left->lettre;
            tableau[i] = '0';
            fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
          //  tableau[i] = '1';
          //  i = i + 1;
       // }

       // if(temp->right != NULL){
            caractere = temp->right->lettre;
            tableau[i] = '1';
            fprintf(fichier_dico,"%c : %s \n",caractere, tableau);
           // tableau[i] = '0';
            i = i + 1;
       // }
        temp = temp->next;
        }
    }

    }

    else{
        return NULL;
    }


    fclose(fichier_dico);
}


void dico_recherche(char caractere,FILE** fichier3,FILE* fichier){
    //on parcourt chaque ligne du fichier dico.txt
    char limite_ligne[10000];
    int j = 0;
    fseek(fichier,0,SEEK_SET);


    while(fgets(limite_ligne,10000,fichier) != NULL){
          if(limite_ligne[0] == caractere){
                for(int i = 0;limite_ligne[i] != '\n';i++){
                    if(limite_ligne[i]== '0' || limite_ligne[i]== '1'){
                        fprintf(*fichier3,"%c ",limite_ligne[i]);
                    }
                }
          }
    }
    fprintf(*fichier3,"\n");


}



void trad_text_bin_huffman()
{
        char caractere;
        FILE* fichier = fopen("dico.txt", "r");
        FILE* fichier2 = fopen("Alice.txt", "r");
        FILE* fichier3 = fopen("Huffman.txt", "r+");
        if(fichier == NULL || fichier2 == NULL || fichier3 == NULL){
            printf("ERREUR DE LECTURE DE FICHIER");
        }
        else{
            do{
                fseek(fichier,0,SEEK_CUR);
                //on lit le fichier Alice.txt qu'on va traduire en binaire avec Huffman grace a la ftc dico_recherche
                caractere = fgetc(fichier2);
                dico_recherche(caractere,&fichier3,fichier);
            } while (caractere!=EOF);
    }
        fclose(fichier);
        fclose(fichier2);
        fclose(fichier3);
}
