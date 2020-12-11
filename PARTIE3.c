#include<stdio.h>
#include<stdlib.h>
#include "PARTIE3.h"
#include "PARTIE2.h"

/*int taille_tableau_de_noeud(Noeud tab)
{
    Noeud temp = tab;
    int i = 0;

    if(tab == NULL){
        return i;
    }
    else{
        while(temp != NULL){
            i = i+1;
            temp = temp + 1;
        }
        return i;
    }
}

Noeud recherche_dichotomie_tableau_noeuds(Noeud tab, char caractere)
{
    int d=0, m;
    int dim;
    Noeud temp,temp2;



    dim = taille_tableau_de_noeud(tab);
    while (dim>d){
    // ici commence la recherche par dichotomie
        m = (d+dim)/2;

        if ('caractere' > 'tab[m].lettre'){
            d = m;
        }
        else if ('caractere' < 'tab[m].lettre'){
            dim = m;
        }
        else if('caractere' == 'tab[m].lettre'){
            tab[m].poids = tab[m].poids + 1;
            return tab;
        }
    }

    // si le caractere n'existe pas encore on l'ajoute à la liste

    if ('caractere' > 'tab[m]->lettre'){
        (tab+m+1) = creer_noeud(caractere,1);
        return tab;

        }
    else if ('caractere' < 'tab[m]->lettre'){
        (tab+m-1) = creer_noeud(caractere,1);
        return tab;
        }
    }


}



void ajout_occurrence()
{
    Noeud tableau[200]= NULL;
    char caractere;


    FILE* fichier = fopen("Alice.txt", "r");
    if(fichier == NULL){
        printf("ERREUR DE LECTURE DE FICHIER");
        }
    else{
        do{
            fseek(fichier,0,SEEK_CUR);
            //on lit le fichier Alice.txt qu'on va mettre dans le tableau de noeuds
            caractere = fgetc(fichier2);
            recherche_dichotomie_tableau_noeuds(tableau,caractere);

        }while (caractere!=EOF);
    }

    fclose(fichier);

}

void affichage_tableau_de_noeuds(Noeud tab)
{
    int i,
    int dimension = taille_tableau_de_noeud(tab);
    for (i = 0; i < dim; i++){
        printf("%c ", tab[i].lettre);
        printf("\n");
    }
}
*/

void trier_tab_noeud(Noeud tab)
{
return NULL;
}

void creer_Huffman_pile(Queue* File, Queue* File, Noeud tab)
{
return NULL;
}

Noeud* org_noeuds_AVL(Noeud* Arbre)
{
return NULL;
}

void compression_texte()
{
return NULL;
}

void decompression_texte()
{
return NULL;
}
